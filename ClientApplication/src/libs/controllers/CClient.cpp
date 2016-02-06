#include "CClient.h"

#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>

#include <QAbstractSocket>
#include <QBuffer>
#include <QImage>
#include <QImageWriter>
#include <QPixmap>

#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlib/CQTcpSocketMock.h"

extern CRepository gRepository;

CClient::CClient(QTcpSocket *aSocket) : mSocket(aSocket) {
  mPortNumber = 1234;
  mReceiveBuffer = 0;
  mSendFile = false;

  QObject::connect(mSocket, SIGNAL(readyRead()),
                   this, SLOT(ReadData()), Qt::DirectConnection);
  PrepareMessageData(384); //usunąć potem
}

CClient::~CClient() {
  delete  mSocket;
  mSocket = nullptr;

  delete mReceiveBuffer;
  mReceiveBuffer = nullptr;
}

void CClient::ReadData() {
  while (mSocket->bytesAvailable() > 0) {
    QByteArray vMessageData = mSocket->readAll();
    // moze konieczne czyszczenie bufora zobaczyc!
    if (vMessageData ==
        QByteArray("NEW FILE")) {
      mSendFile = true;
    }
  }
}

bool CClient::ConnectToHost(QString aHost) {
  mSocket->connectToHost(aHost, mPortNumber);
  qDebug() << "state before" << mSocket->state();
  bool vHasBeenEstablished = mSocket->waitForConnected(90000);
  qDebug() << "state after" << mSocket->state();
  qDebug() << "vHasBeenEstablished in connectToHost:" << vHasBeenEstablished;

  if (vHasBeenEstablished == false) {
      qDebug() << mSocket->error();
      throw mSocket->error();
  }

  return vHasBeenEstablished;
}

QByteArray CClient::ConvertImageToByteArray(const QImage &aImage) {
  QBuffer vBuffer;

  QImageWriter vWriter(&vBuffer, "JPG");
  vWriter.write(aImage); // unikniecie vWriter.write(*(*vIterator));
  return vBuffer.data();
}

QByteArray CClient::PrepareMessageData(int16_t aChecksum) {
  QByteArray vData(qPrintable(QString::number(aChecksum)));
  vData.insert(0, '>');
  vData.insert(1, '>');
  vData.append("<");

  return vData;
}

bool CClient::WriteData(const QByteArray &aData) {
  if (mSocket->state() == QAbstractSocket::ConnectedState) {
    mSocket->write(IntToArray(aData.length()));
    mSocket->write(aData);

    return mSocket->waitForBytesWritten();
  } else {

    return false;
  }
}

bool CClient::WriteMessage(const QByteArray &aData) {
  if (mSocket->state() == QAbstractSocket::ConnectedState) {
    mSocket->write(aData);
    return mSocket->waitForBytesWritten();
  } else {
    return false;
  }
}

int16_t CClient::CalculateFileDataChecksum(QByteArray aData) {
  int16_t vChecksum {};

  for (int i = 0; i < aData.length(); ++i) {
    vChecksum += aData[i];
  }

  return vChecksum;
}

QByteArray CClient::IntToArray(int32_t aSource) {
  QByteArray vData;
  QDataStream vStream(&vData, QIODevice::ReadWrite);
  vStream << aSource;

  return vData;
}

void CClient::UpdateServerPhotos() {
  gRepository.PopulateRepository();
  QStringList vImagesPath = gRepository.GetImages();

  // wersja finalna:
  foreach (QString vPath, vImagesPath) {
      QImage vImage(vPath);
   QByteArray vData = ConvertImageToByteArray(vImage);
   int16_t vFileChecksum = CalculateFileDataChecksum(vData);
   QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
   WriteMessage(vChecksumByte);
   sleep(3);

   if (mSendFile) {
     WriteData(vData);
     mSendFile = false;
   }
 }

  // wersja 1 testowa 1 obrazek sprawdzenie i  wysłanie:
  /*
   QImage image(vPath);// lub .jpeg
  qDebug() << "size image in update serv photo func:" << image.size();
   QByteArray vData = ConvertImageToByteArray(image);
   int16_t vFileChecksum = CalculateFileDataChecksum(vData);
   QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
   qDebug() << "vChecksumByte" << vChecksumByte;
   WriteMessage(vChecksumByte);
   sleep(3);
   qDebug() << "mSendFile Flag:" << mSendFile;

   if (mSendFile) {
     WriteData(vData);
     mSendFile = false;
   }*/
}
