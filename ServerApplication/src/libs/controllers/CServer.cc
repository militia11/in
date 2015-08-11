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
    qDebug() << "polaczono";
    mSocket->write("hello client\r\n");
    QByteArray aa = mSocket->readAll();
    mSocket->write(aa);

}

void CServer::ReadyRead() {
    QByteArray vData = mSocket->readAll();

    if (!vData.isEmpty()) { // nie wiem czy ten if ma sens?
      mSocket->write("Odebrano dane.\r\n");
    }
    emit SendData(vData);
    qDebug() << "Dane : " << vData ;
    //socket->waitForBytesWritten(3000);
    //socket->flush();
}
