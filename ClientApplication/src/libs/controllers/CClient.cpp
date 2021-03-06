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
  mSend = false;
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
		QByteArray()) {
	  emit SetStatus ("IN SERVER");
	  vMessageData.clear();
	} else if (vMessageData == QByteArray("NOT AVAILABLE")) {
	  WriteData(mActualData);
	  emit SetStatus ("NOT AVAILABLE");
	  vMessageData.clear();
      if (WriteData(mActualData)) {
            vMessageData.clear();
      } else {
            vMessageData.clear();
      }
	}

	mActualData.clear();
  }
}

void CClient::WaitForChangeStatus() {
  int vMilliseconds = 0;
  int vTimeout = 5000; // milliseconds

  QTime vTimer;
  vTimer.start();
  do {
	vMilliseconds = vTimer.elapsed();
  } while (vMilliseconds < vTimeout);
}

void CClient::ManageData(QByteArray aData) {
  switch (mServerAvailability) {
	case status_in_server:
	  mServerAvailability = status_unknown;
	  break;

	case status_not_available:
	  WriteData(aData);
	  mServerAvailability = status_unknown;
	  break;

	default: {
	} // do nothing
	break;
  }
}

bool CClient::ConnectToHost(QString aHost) {
  mSocket->connectToHost(aHost, mPortNumber);
  bool vHasBeenEstablished = mSocket->waitForConnected();

  if (vHasBeenEstablished == false) {
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

void CClient::CheckPhoto(int aPhotoNumber)
{	QString vPath = gRepository.GetImagePath(aPhotoNumber);
	QImage vImageToSend(vPath);
	QBuffer vBuffer;
	QImageWriter vWriter(&vBuffer, "JPG");
	vWriter.write(vImageToSend);
	mActualData = vBuffer.data();
	int32_t vFileChecksum = CalculateFileDataChecksum(mActualData);
	qDebug()<< "file czeksum in check foto:\n" << vFileChecksum;
    emit SetStatus(QString::number(vFileChecksum));
	QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
	qDebug() << "vChecksumByte in check foto:\n" << vChecksumByte;
	WriteMessage(vChecksumByte);
}

QByteArray CClient::PrepareMessageData(int aChecksum) {
  QByteArray vData(qPrintable(QString::number(aChecksum)));
  vData.insert(0, '>');
  vData.insert(1, '>');
  vData.append("<");

  return vData;
}

bool CClient::WriteData(const QByteArray &aData) {
  if (mSocket->state() == QAbstractSocket::ConnectedState) {
	mSocket->write(IntToArray(aData.length()));
	mSocket->waitForBytesWritten();
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

int32_t CClient::CalculateFileDataChecksum(QByteArray aData) {
  int32_t vChecksum {};

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
  QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
  QStringList vPicturesLocation = QStandardPaths::standardLocations(
									QStandardPaths::PicturesLocation);
  QString vPath = vPicturesLocation.at(0);
  QDir vDir(vPath);
  QStringList vAllFiles =  vDir.entryList(QDir::Files);
  vPath += "/a.jpg";
  qDebug() << "Koncowy path:" << vPath;
  QImage vImageToSend(vPath);
  QBuffer vBuffer;
  QImageWriter vWriter(&vBuffer, "JPG");
  vWriter.write(vImageToSend);
  mActualData = vBuffer.data();
  uint32_t vFileChecksum = CalculateFileDataChecksum(mActualData);
  qDebug() << "vChecksum one\n" << vFileChecksum;
  QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
  qDebug() << "vChecksumByte\n" << vChecksumByte;
}
