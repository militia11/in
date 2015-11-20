#ifndef CReceiver_H
#define CReceiver_H

#include <inttypes.h>  // uint_t* and int_t* types

#include <QTcpSocket>
#include <QObject>

#include "src/libs/controllers/CStorePhotoTransaction.h"
#include "src/libs/controllers/CRetrievePhotoTransaction.h"
#include "src/libs/controllers/IReceiver.h"
#include "src/libs/dao/CChecksumList.h"

/**
 * @brief The ReceiveDataMode is enumeration of kinds receive data
 *        modes for Receiver
 */
enum ReceiveDataMode {
    Mode_Receive_File_Data      = 1,
    Mode_Receive_File_Checksum  = 2
};

/**
 * @brief The CReceiver class receive photos from client in
 *        client-server architecture
 *
 * CReceiver class inherits from QObject. This class have responsibility
 * of coordinate communication with CReceiver class from Android-side application
 *
 * @todo dopisac wiecej pozniej
 */
class CReceiver : public IReceiver {
    Q_OBJECT

	public:
    /**
     * @brief CReceiver constructor
     */
    CReceiver();

    /**
     * @brief CReceiver destructor
     */
    ~ CReceiver();

    /**
     * @brief Method called to get CReceiver class member mSocket
		 *        which represent socket
     *
     * @return CReceiver socket
     */
    QTcpSocket *GetSocket() const;

	protected slots:
		/**
		 * @brief Slot called when connection lost
		 */
		void Disconnected();

    /**
		 * @brief Method called on new incomming data
     */
    void NewData();

  signals:
    /**
		 * @brief Signal emited when client disconnect from server
     */
    void Disconnect();

    /**
		 * @brief Signal emited when error occured a socket
     *
		 * @param aSocketError is a QTcpSocket::SocketError
     */
    void Error(QTcpSocket::SocketError aSocketError);

    /**
		 * @brief Signal emited when was read data
		 *
		 * @param aData is a QByteArray data which was read
     */
    void ReadData(QByteArray aData);

    /**
     * @brief MessageStatus  Signal emited to send status for mainly to the main status bar
		 *
		 * @param aMessage Message to send
     * @param aTimeMsc Time in miliseconds
     */
    void MessageStatus(const char *aMessage, int aTimeMsc);

  protected:
    /**
     * @brief MessageFormatException print message format exception
		 *
		 * @param vException is message exception
     */
    void MessageFormatException(const char *aException);

    /**
		 * @brief Method to respone information to client
		 */
		void ResponeToClient(const char *aMessage = 0);

		/**
		 * @brief Method called when server receive incoming connection,
		 *        client is connecting to specify port
		 */
		void Connect(QTcpSocket *aSocket);

		/**
		 * @brief ConvertMessageArrayToInt method convert message
		 *        to int
		 *
		 * @return Checksum
		 */
    int ConvertMessageArrayToInt();

    /**
     * @brief ServeFileData serve file data
		 *        from incoming connection
     */
    void ServeReceivedFileData();

    /**
		 * @brief ByteArrayToInt convert array to int
     *
		 * @param aData array
		 * @return Integer number converted from array
     */
    int32_t ByteArrayToInt(QByteArray aData);

    /**
     * @brief RouteData function switch data to
     *        CCheckSumList class or file data to save
		 *        in server
     *
		 * @param aData is data to route
     */
    void RouteData(char aData);

    /**
		 * @brief Serve single received message
     */
    void ServeReceivedMessage();

    /**
		 * @brief Check has message correct format
     *
     * Message should consist from:
     * - message begin chars: ">>"
     * - data as hex-ascii string
     * - end message char: "<"
     *
     * @param aMessage Message to check
     * @return True for correct format, false for incorrect
     */
		bool HasMessageCorrectFormat(char *aMessage);

    /**
     * @brief CalculateFileDataChecksum calculate message checksum
		 *        to compare with expected
     *
		 * @return Checksum calculated as youngest byte of sum of all bytes
     */
    uint16_t CalculateFileDataChecksum(QByteArray aData);

    /**
     * @brief Method connect socket's signals to
     *        represent client's (CReceiver) slots
     */
    void ConnectSocketSignals();

    /**
		 * @brief mSocket of Client
     */
    QTcpSocket *mSocket;

    /**
		 * @brief mReceiveBuffer is buffer of received data
     */
    QByteArray *mReceiveBuffer;

    /**
     * @brief mDataSize is size of receive buffer
     */
    int32_t *mDataSize;

    /**
     * @brief mReceiveDataMode is mode of receiving data
     */
    ReceiveDataMode mReceiveDataMode;

    /**
     * @brief mMessageClntFileChecksum is checksum of file sended from client
     */
    char mMessageFileChecksum[1024];

    /**
     * @brief mMessageSize is size of message sended from client
     */
    int mMessageSize;

    /**
     * @brief mReceiveByteCount is counter of received bytes
     */
    int mReceiveByteCount;
};

#endif // CReceiver_H
