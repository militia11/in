#include "CServer.h"
#include <QTcpSocket>

CServer::CServer(QObject *parent)
    : mClient(NULL),
    QTcpServer(parent)
{

}


void CServer::Run()
{

}


void CServer::ServeReceivedMessage(QByteArray aData)
{

}


void CServer::IncomingConnection()
{

}
