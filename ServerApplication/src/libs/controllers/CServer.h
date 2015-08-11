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
    //CServerThread * mServerThread;
        QTcpSocket *mSocket;
};

#endif // CSERVER_H
