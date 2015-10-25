#ifndef CCLIENTMOCK_H
#define CCLIENTMOCK_H

#include "libs/controllers/IClient.h"

/**
 * @brief Mock of CClient used in unit tests
 */
class CClientMock : public IClient {
  public:

		const QString GetLog() const;
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
		 * @brief Method called to get CClient class member mSocket
		 *        which represent socket
     *
		 * @return CCLient socket
     */
    QTcpSocket *GetSocket() const;

    //public slots:
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

    //private slots:
    /**
     * @brief Slot called when connection closed.
     */
    void Disconnected();

    ///@todo opis
    int ConvertMessageArrayToInt();

    /**
         * @brief ServeFileData serve file data
         *            from incoming connection.
     */
    void ServeReceivedFileData();

    /**
     * @brief ByteArrayToInt convert array to int.
     *
         * @param aData array.
     *
     * @return Integer number converted from array.
     */
    int32_t ByteArrayToInt(QByteArray aData);

    /**
         * @brief RouteData function switch data to
         *        CCheckSumList class or file data to save
         *        in server.
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
     * - message begin chars: ">>"
     * - data as hex-ascii string
     * - end message char: "<"
     *
     * @return True for correct format, False for incorrect.
     */
    bool HasMessageCorrectFormat(char *aMessage);

    /**
     * @brief CalculateFileDataChecksum calculate message checksum
     *               to compare with expected.
     *
     * @return Checksum calculated as youngest byte of sum of all bytes.
     */
    uint16_t CalculateFileDataChecksum(QByteArray aData);

    /**
         * @brief Method connect socket's signals to
         *        represent client's (CClient) slots.
     */
    inline void ConnectSocketSignals();

  protected:
    /**
     * @brief Log of called methods
     */
		mutable QString mLog;
};

#endif // CCLIENTMOCK_H
