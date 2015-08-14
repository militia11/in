#ifndef CCLIENT_H
#define CCLIENT_H

#include <QTcpSocket>

class CClient : public QTcpSocket
{
    Q_OBJECT

public:
    explicit CClient(QObject *parent = 0);

signals:

public slots:

private:
    QByteArray mReceiveBuffer;
    int mReceiveByteCnt;
    int mReceiveFrameNOKCnt;
};

#endif // CCLIENT_H
