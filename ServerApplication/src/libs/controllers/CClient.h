#ifndef CCLIENT_H
#define CCLIENT_H

#include "libs/dao/CChecksumList.h"

#include "libs/controllers/CAddToDBTransaction.h"
#include "libs/controllers/CRetrieveFromDBTransaction.h"

#include <inttypes.h> //uint_t* and int_t* types
#include <QTcpSocket>
#include <QObject>

/**
 * @brief The ReceiveDataMode is enumeration of kinds receive data
 *  modes for Client
 */
enum ReceiveDataMode {
    Mode_Receive_File_Data          = 1,
		Mode_Receive_File_CheckSum			= 2
};

/**
 * @brief The CClient class represents client in client-server architecture.
 *
 * @details CClient class inherits from QObject. This class have responsibility of coordinate
 * communication with client from Android device.
 * @todo dopisac pozniej
 * */
class CClient : public QObject {

    Q_OBJECT

  public:
    /**
    * @brief CClient constructor.
    */
    explicit CClient(QObject *aParent = 0);

    /**
    * @brief CClient destructor.
    */
    ~ CClient();

    /**
     * @brief Method called when server receive incoming connection,
     *  client is connecting to specify port.
     */
    void Connect(QTcpSocket *aSocket);

    /**
     * @brief Method to respone some information to client.
     */
    void ResponeToClient(QByteArray aData = 0);

    /**
     * @brief Method called to get CClient class member mSocket
     * which represent socket.
     */
    QTcpSocket *GetSocket() const;

  public slots:
    /**
     * @brief Method called on new incomming data.
     */
    void NewData();

  signals:

    /**
    * @brief Signal emited when client disconnect from server.
    */
    void Disconnect();

    /**
    * @brief Signal emited when error occured a socket.
    *
    * @param aSocketError is a QTcpSocket::SocketError.
    */
    void Error(QTcpSocket::SocketError aSocketError);

    /**
    * @brief Signal emited when was read data.
    *
    * @param aData is a QByteArray data which was read.
    */
    void ReadData(QByteArray aData);

    /**
     * @brief Signal emited to send status for mainly to the main status bar.
     */
    void MessageStatus(const char *aMessage, int aTimeMsc);

  private slots:
    /**
     * @brief Slot called when connection closed.
     */
    void Disconnected();

	private:
		void ConvertHexAsciiToBinary(const char *aData, int aLen,
																 char *aTarget);
		void ConvertBinaryToHexAscii(const char *aData, int aLen,
																 char *aTarget);
    QString PrepareSendingToClientMessage(int aChecksum);

		int ConverMessageArraytToInt();

		/**
		 * @brief ServeFileData serve file data.
		 *  from incoming connection.
		 */
		void ServeReceivedFileData();

    int32_t ByteArrayToInt(QByteArray aData);

		/**
		 * @brief RouteData function switch data to
		 * CCheckSumList class or file data to save
		 * in server.
		 *
		 * @param aData is data to route.
		 */
		void RouteData(char aData);

    /**
     * @brief Serve single received message.
     */
		void ServeReceivedMessage();

    /**
     * @brief Check has message correct format.
     *
     * Message should consist from:
     * - message begin char: ">"
     * - data as hex-ascii string
					 * - end message char: "<"
     *
				 * @return TRUE for correct format, FALSE for incorrect.
     */
		bool HasMessageCorrectFormat(char *aMessage);

		/**
		* @brief CalculateFileDataChecksum calculate message checksum
		* to compare with expected.
		*
		* @return Checksum calculated as youngest byte of sum of all bytes.
		*/
		uint8_t CalculateFileDataChecksum(QByteArray aData);

    /**
     * @brief Method connect socket's signals to
     * represent client's (CClient) slots
     */
    inline void ConnectSocketSignals();

    QTcpSocket *mSocket;
		QByteArray *mReceiveBuffer;
		int32_t *mDataSize;
    ReceiveDataMode mReceiveDataMode;
		char mMessageClntFileChecksum[1024];
		int mMessageSize;
    int mReceiveByteCnt;
    int mReceiveFrameNOKCnt;
		int mReceiveFrameFaultCnt;


};

#endif // CCLIENT_H
