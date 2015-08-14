#include "CClient.h"

CClient::CClient(QObject *parent) :
    mReceiveBuffer(0),
    mReceiveByteCnt(0),
    mReceiveFrameNOKCnt(0),
    QTcpSocket(parent)
{
}

void CClient::ReadyRead()
{
    QByteArray dane = readAll();

    if (!dane.isEmpty()) { // nie wiem czy ten if ma sens?
      this->write("Odebrano dane.\r\n");
    }

    emit ReadData(dane);
    //qDebug() << mSocketDescriptor << "Dane : " << dane ;// sygnal wyslanie danych
    //socket->waitForBytesWritten(3000);
    //socket->flush();
}
