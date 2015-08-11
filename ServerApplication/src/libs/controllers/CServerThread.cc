#include "CServerThread.h"

CServerThread::CServerThread(int aId, QObject *aParent)
    :mSocketDescriptor(aId){
    Q_UNUSED(aParent)
}

void CServerThread::Run()
{
    qDebug() << mSocketDescriptor << "Wątek startuje";
    mSocket = new QTcpSocket();

    if ( !mSocket->setSocketDescriptor(mSocketDescriptor) ) {
      emit Error(mSocket->error());
      return;
    }

//    QObject::connect(mSocket, SIGNAL(readyRead()), this, SLOT(ReadyRead()),
//             Qt::DirectConnection);
//    QObject::connect(mSocket, SIGNAL(disconnected()), this, SLOT(ConnectionLosted()),
//             Qt::DirectConnection);
    qDebug() << mSocketDescriptor << "Połączony... ";
    //exec();
}

void CServerThread::ReadyRead()
{
    QByteArray dane = mSocket->readAll();

    if (!dane.isEmpty()) { // nie wiem czy ten if ma sens?
      mSocket->write("Odebrano dane.\r\n");
    }

    qDebug() << mSocketDescriptor << "Dane : " << dane ;// sygnal wyslanie danych
    //emit moznaCzytac(dane);
    //socket->waitForBytesWritten(3000);
    //socket->flush();
}

void CServerThread::ConnectionLosted()
{

}

