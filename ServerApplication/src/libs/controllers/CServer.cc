#include "CServer.h"

CServer::CServer(QObject *parent) :
    QTcpServer(parent),
    mSocket(NULL),
    mReceiveByteCnt(0),
    mReceiveBuffer(NULL) // może 0
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

    connect(mSocket, SIGNAL(readyRead()), this, SLOT(NewData()));
    mSocket->write("Witaj kliencie\r\n");
    qDebug() << "Połączono";
}

void CServer::NewData() {
    QByteArray vData = mSocket->readAll();

    int vDataLength = vData.length();
    for (int i = 0; i < vDataLength; i++) {
        if (vData[i] == '>') {	// SYNC frame start BYTE
            mReceiveByteCnt = 0;
        }

        if (mReceiveByteCnt >= 1023) { // Prevent buffer overflow
            mReceiveByteCnt = 0;
        }

        mReceiveBuffer[mReceiveByteCnt] = vData[i];
        ++mReceiveByteCnt;

        if (vData[i] == 0x0A) {
            //ServeReceivedMessage(mReceiveBuffer, mReceiveByteCnt);
            mReceiveByteCnt = 0;
        }
    }

      /*nie konieczne*/mSocket->write("Odebrano dane: " );
      /*nie konieczne*/mSocket->write(vData);


    emit SendData(vData);
    qDebug() << "Dane : " << vData ;
    qDebug() << vData.length();
}
