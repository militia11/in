#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "libs/controllers/CServerThread.h"

class CServer : public QTcpServer {

    Q_OBJECT

public:
    CServer(QObject *parent = 0);
    void Run();

public slots:
    void IncomingConnection();
    void ReadyRead();

signals:
    void SendData(QByteArray aData);

private:
    QTcpSocket *mSocket;
    //CServerThread * mServerThread;
};

#endif // CSERVER_H
