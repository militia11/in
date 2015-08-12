#include "CServer.h"

CServer::CServer(QObject *parent) :
    QTcpServer(parent),
    mSocket(0)
{
    connect(this, SIGNAL(newConnection()),this, SLOT(IncomingConnection()));
}


void CServer::Run() {
    if (!this->listen(QHostAddress::Any, 1234)) {
      qDebug() << "Nie można wystartować serwera";
    } else {
      qDebug() << "Nasłuchuje...";
    }
}

void CServer::IncomingConnection() {
    mSocket = this->nextPendingConnection();

    connect(mSocket, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
    mSocket->write("Witaj kliencie\r\n");
    qDebug() << "Połączono";
}

void CServer::ReadyRead() {
    QByteArray vData = mSocket->readAll();

    if (!vData.isEmpty()) { // nie wiem czy ten if ma sens?
      mSocket->write("Odebrano dane: " );
      mSocket->write(vData);
    }
    emit SendData(vData);
    qDebug() << "Dane : " << vData ;
}
