#ifndef CCLIENT_H
#define CCLIENT_H

#include <QTcpSocket>

class CClient : public QTcpSocket
{
    Q_OBJECT

public:
    explicit CClient(QObject *parent = 0);

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
    QByteArray mReceiveBuffer;
    int mReceiveByteCnt;
    int mReceiveFrameNOKCnt;
};

#endif // CCLIENT_H
