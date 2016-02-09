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
  mServerAvailability = status_unknown;

  QObject::connect(mSocket, SIGNAL(readyRead()),
                   this, SLOT(ReadData()), Qt::DirectConnection);
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
    ///@todo moze konieczne czyszczenie bufora zobaczyc!

    if (vMessageData ==
        QByteArray("IN SERVER")) {
      mServerAvailability = status_in_server;
    } else if (vMessageData == QByteArray("NOT AVAILABLE")) {
      mServerAvailability = status_not_available;
    }
  }
}

void CClient::WaitForChangeStatus() {
  int vMilliseconds = 0;
  int vTimeout = 10000; // milliseconds

  QTime vTimer;
  vTimer.start();

  do {
    vMilliseconds = vTimer.elapsed();
    usleep(1000);
  } while (
    (mServerAvailability == status_unknown) && (vMilliseconds < vTimeout));
}

void CClient::ManageData(QByteArray aData) {
  switch (mServerAvailability) {
    case status_in_server:
      WriteData(aData);
      mServerAvailability = status_unknown;
      break;

    case status_not_available:
      ///@todo moze ponowne wyslanie?
      mServerAvailability = status_unknown;
      break;

    default:
      // do nothing
      break;
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
  vWriter.write(aImage);
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
    WaitForChangeStatus();
    ManageData(vData);
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
