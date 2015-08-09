#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
//#include <CServerThread.h>

class CServer : public QTcpServer {

    Q_OBJECT

public:
    CServer(QObject *parent = 0);
    void Run();
    void IncomingConnection(int aSocketDescriptor);

signals:
    void SendData(QByteArray aData);
};

#endif // CSERVER_H
