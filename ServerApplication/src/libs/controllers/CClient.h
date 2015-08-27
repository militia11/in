#ifndef CCLIENT_H
#define CCLIENT_H

#include <inttypes.h>
#include <QTcpSocket>
#include <QObject>

/**
 * @brief The ReceiveDataMode enum, enumeration of kinds receive data
 *  modes for Client
 */
enum ReceiveDataMode {
		Mode_Receive_File_Data					= 1,
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
    void ResponeToClient(const char *aMessage, QByteArray aData = 0);

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
		void ServeFileData();

    int32_t ByteArrayToInt(QByteArray aData);

		void RouteData(char aData);

    /**
     * @brief Serve single received message.
     */
		void ServeReceivedMessage(); //int aReceiveByteCnt

    /**
     * @brief Check has message correct format.
     *
     * Message should consist from:
     * - message begin char: ">"
     * - module id:
     *      - "L" for list of files
     *      - "D" for files data
     * - data as hex-ascii string
     * - checksum (1 byte) as 2 hex-ascii chars
     * - new line as CR LF.
     *
     * @return TRUE for correct format, FALSE for incorrect.
     */
		bool HasMessageCorrectFormat(char *aMessage);

    /**
     * @brief Validate message checksum.
     *
     * @param aData message to check in binary form.
     *
     * @return TRUE for correct checksum, FALSE if incorrect.
     */
		bool HasMessageCorrectChecksum(QByteArray aData);

    /**
     * @brief Convert hex-ascii string into binary data
     *
     * @param aData hex-ascii string
     * @param aLen length of hex-ascii string
     * @param mBinaryMessageData output parameter - pointer to output byte array
     */

    /**
     * @brief Calculate message checksum to compare with expected.
     *
     * @return Checksum calculated as youngest byte of sum of all bytes.
     */
		uint8_t CalculateMessageChecksum(QByteArray aData);

  private:
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
