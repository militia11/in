#include "CServer.h"
#include <QTcpSocket>
#include <QDebug>

CServer::CServer(QObject *parent)
    : mClient(NULL),
    QTcpServer(parent)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(IncomingConnection()));
}


void CServer::Run()
{
    if(!listen(QHostAddress::Any, 1234)) {
        qDebug() << "Nie można wystartować serwera";
    } else {
        qDebug() << "Serwer nasłuchuje ...";
    }
}


void CServer::ServeReceivedMessage(QByteArray aData)
{

}

CClient *CServer::GetClient() const
{
    return mClient;
}


void CServer::IncomingConnection()
{
    mClient = new CClient();
    QTcpSocket * vSocket = nextPendingConnection();
    mClient->SetSocket(vSocket);
    mClient->SendData("Witaj kliencie");
}

void CServer::NewData()
{

}
