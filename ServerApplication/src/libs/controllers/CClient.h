#ifndef CCLIENT_H
#define CCLIENT_H

#include <inttypes.h>
#include <QTcpSocket>
#include <QObject>

enum ReceiveDataMode {
		Mode_UnknownData      = 0,
		Mode_Receive_FileList = 1,
		Mode_Receive_Files    = 2
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
		explicit CClient(QObject *aParent = 0);
		~ CClient();

		void Connect(QTcpSocket *aSocket);
		void ResponeToClient(const char *aMessage, QByteArray aData = 0);

		QTcpSocket *GetSocket() const;

	public slots:

		/**
		 * @brief Method called on new incomming data
		 */
		void NewData();

	signals:
		void Disconnect();

		/**
		* @brief Signal emited when error ocured socket
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


		void MessageStatus(const char *aMessage, int aTimeMsc);

	private slots:
		void Disconnected();

	private:
		void RouteData(ReceiveDataMode mReceiveDataMode, char aData);

		/**
		 * @brief Serve single received message
		 */
		void ServeReceivedMessage(); //int aReceiveByteCnt

		/**
		 * @brief Check has message correct format
		 *
		 * Message should consist from:
		 * - message begin char: ">"
		 * - module id:
		 *      - "L" for list of files
		 *      - "D" for files data
		 * - data as hex-ascii string
		 * - checksum (1 byte) as 2 hex-ascii chars
		 * - new line as CR LF
		 *
		 * @return TRUE for correct format, FALSE for incorrect
		 */
		bool HasMessageCorrectFormat(QByteArray aData);

		/**
		 * @brief Validate message checksum
		 *
		 * @param aData message to check in binary form
		 *
		 * @return TRUE for correct checksum, FALSE if incorrect
		 */
		bool HasMessageCorrectChecksum(QByteArray aData);

		/**
		 * @brief Convert hex-ascii string into binary data
		 *
		 * @param aData hex-ascii string
		 * @param aLen length of hex-ascii string
		 * @param mBinaryMessageData output parameter - pointer to output byte array
		 */
		//void ConvertHexAsciiToBinary(BYTE *aData, int aLen, BYTE *aBinaryMessageData);

		/**
		 * @brief Calculate message checksum to compare with expected
		 *
		 * @return Checksum calculated as youngest byte of sum of all bytes
		 */
		//uint8_t CalculateMessageChecksum(BYTE *aData, int aLen);

	private:
		QTcpSocket *mSocket;
		QByteArray mReceiveBuffer;
		ReceiveDataMode mReceiveDataMode;
		int mReceiveByteCnt;
		int mReceiveFrameNOKCnt;
		int mReceiveFrameFaultCnt;
};

#endif // CCLIENT_H
