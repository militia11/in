#ifndef CCLIENT_H
#define CCLIENT_H

#include <QTcpSocket>
#include <QObject>
class CClient : public QObject
{
    Q_OBJECT

public:
    explicit CClient(QObject *parent = 0);
    void SendData(char *aData);
    void SetSocket(QTcpSocket * aSocket);
    QTcpSocket *GetSocket() const;

signals:
    void Error(QTcpSocket::SocketError aSocketError);

    /**
     * @brief Signal emit when was read data
     *
     * @param aData is QByteArray data which is sending
     */
    void ReadData(QByteArray aData);

public slots:
    void ReadyRead();

private:
    QTcpSocket *mSocket;
    QByteArray mReceiveBuffer;
    int mReceiveByteCnt;
    int mReceiveFrameNOKCnt;
};

#endif // CCLIENT_H
