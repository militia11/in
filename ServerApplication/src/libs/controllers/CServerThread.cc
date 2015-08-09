#include "CServerThread.h"

CServerThread::CServerThread(int aId, QObject *aParent)
    : QThread(aParent) {
}

void CServerThread::Run()
{
    qDebug() << mScocketDescriptor << "Wątek startuje";
    mSocket = new QTcpSocket();

    if ( !mSocket->setSocketDescriptor(mScocketDescriptor) ) {
      emit Error(mSocket->error());
      return;
    }

    connect( mSocket, SIGNAL(readyRead()), this, SLOT(moznaCzytac()),
             Qt::DirectConnection);
    connect( mSocket, SIGNAL(disconnected()), this, SLOT( connectionLosted()),
             Qt::DirectConnection);
    qDebug() << mScocketDescriptor << "Połączony... ";
    exec();
}

void CServerThread::ReadyRead()
{
    QByteArray dane = mSocket->readAll();

    if (!dane.isEmpty()) { // nie wiem czy ten if ma sens?
      mSocket->write("Odebrano dane.\r\n");
    }

    qDebug() << mScocketDescriptor << "Dane : " << dane ;// sygnal wyslanie danych
    //emit moznaCzytac(dane);
    //socket->waitForBytesWritten(3000);
    //socket->flush();
}

void CServerThread::Disconected()
{

}
