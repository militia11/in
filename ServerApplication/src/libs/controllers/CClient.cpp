#include "CClient.h"

CClient::CClient(QObject *parent) :
    mSocket(NULL),
    mReceiveBuffer(0),
    mReceiveByteCnt(0),
    mReceiveFrameNOKCnt(0),
    QObject(parent)
{
}

void CClient::SetSocket(QTcpSocket *aSocket)
{
    if(aSocket) {
        mSocket = aSocket;
        QObject::connect(mSocket, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
    } else {
        emit mSocket->error();
    }

}

QTcpSocket *CClient::GetSocket() const
{
    return mSocket;
}

void CClient::SendData(char *aData)
{
    mSocket->write(aData);
}

void CClient::ReadyRead()
{
    QByteArray vData = mSocket->readAll();

    if (!vData.isEmpty()) { // nie wiem czy ten if ma sens?
      mSocket->write("Odebrano dane :");
      mSocket->write(vData);
    }

    emit ReadData(vData);

}
