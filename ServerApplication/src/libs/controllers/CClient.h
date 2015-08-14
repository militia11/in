#ifndef CCLIENT_H
#define CCLIENT_H

#include <QTcpSocket>
#include <QObject>

enum ReceiveDataMode {
    Mode_UnknownData      = 0,
    Mode_Receive_FileList = 1,
    Mode_Receive_Files    = 2
};

class CClient : public QObject
{
    Q_OBJECT

public:
    explicit CClient(QObject *aParent = 0);
    ~ CClient();
    void SendData(char *aData);
    void Connect(QTcpSocket * aSocket);

    QTcpSocket *GetSocket() const;

public slots:

    /**
     * @brief Method called on new incomming data
     *
     * @param aData is QByteArray buffer
     * @param aLen length of new data
     */
    void NewData();

private slots:
    void Disconnected();

private:
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
     * 		- "L" for ?
     * 		- "D" for data
     * - data as hex-ascii string
     * - checksum (1 byte) as 2 hex-ascii chars
     * - new line as CR LF
     *
     * @return TRUE for correct format, FALSE for incorrect
     */
    bool HasMessageCorrectFormat(QByteArray aData);

private:
    void RouteData(ReceiveDataMode mReceiveDataMode, char aData, int i);

signals:
    void Error(QTcpSocket::SocketError aSocketError);

    /**
    * @brief Signal emit when was read data
    *
    * @param aData is QByteArray data which is sending
    */
    void ReadData(QByteArray aData);

private:
    QTcpSocket *mSocket;
    QByteArray mReceiveBuffer;
    ReceiveDataMode mReceiveDataMode;
    int mReceiveByteCnt;
    int mReceiveFrameNOKCnt;
};

#endif // CCLIENT_H
