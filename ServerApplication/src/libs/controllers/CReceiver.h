#ifndef CReceiver_H
#define CReceiver_H

#include <inttypes.h> //uint_t* and int_t* types

#include <QTcpSocket>
#include <QObject>

#include "../ServerApplication/src/libs/controllers/CStorePhotoTransaction.h"
#include "../ServerApplication/src/libs/controllers/CRetrievePhotoTransaction.h"
#include "../ServerApplication/src/libs/controllers/IReceiver.h"
#include "../ServerApplication/src/libs/dao/CChecksumList.h"

/**
 * @brief The ReceiveDataMode is enumeration of kinds receive data
 *        modes for Receiver
 */
enum ReceiveDataMode {
    Mode_Receive_File_Data      = 1,
    Mode_Receive_File_Checksum  = 2
};

/**
 * @brief The CReceiver class receive photos from client in client-server architecture
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
     * @brief Method called when server receive incoming connection,
    	 *        client is connecting to specify port
     */
    void Connect(QTcpSocket *aSocket);

    /**
    	 * @brief Method to respone information to client
     */
    void ResponeToClient(QByteArray aData = 0);

    /**
     * @brief Method called to get CReceiver class member mSocket
    	 *        which represent socket
     *
     * @return CReceiver socket
     */
    QTcpSocket *GetSocket() const;

  public slots:
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
    	 * @brief Signal emited to send status for mainly to the main status bar
     */
    void MessageStatus(const char *aMessage, int aTimeMsc);

  private slots:
    /**
    	 * @brief Slot called when connection lost
     */
    void Disconnected();

  protected:
    /**
     * @brief Mock of ConvertMessageArrayToInt method
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
    	 * @return True for correct format, False for incorrect
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
