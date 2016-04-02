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
                emit action(5);
                vMessageData.clear();
                mServerAvailability = status_in_server;
            } else if (vMessageData == QByteArray("NOT AVAILABLE")) {
                 emit action(2);
                 vMessageData.clear();
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
        } while ((mServerAvailability == status_unknown) && (vMilliseconds < vTimeout));
}

void CClient::ManageData(QByteArray aData) {
    emit action(99);
		switch (mServerAvailability) {
		case status_in_server:
			WriteData(aData);
			mServerAvailability = status_unknown;
			break;

		case status_not_available:
			///@todo moze ponowne wyslanie?
			mServerAvailability = status_unknown;
			break;

		default: {} // do nothing
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

QByteArray CClient::PrepareMessageData(uint16_t aChecksum) {
		QByteArray vData(qPrintable(QString::number(aChecksum)));
		vData.insert(0, '>');
		vData.insert(1, '>');
		vData.append("<");

		return vData;
}

bool CClient::WriteData(const QByteArray &aData) {
        if (mSocket->state() == QAbstractSocket::ConnectedState) {
            mSocket->write(IntToArray(aData.length()));
            bool x = mSocket->waitForBytesWritten();
            usleep(2000);
            mSocket->write(aData);

             mSocket->waitForBytesWritten();
            return x;
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

uint16_t CClient::CalculateFileDataChecksum(QByteArray aData) {
        uint16_t vChecksum {};

		for (int i = 0; i < aData.length(); ++i) {
            vChecksum += aData[i];
		}

        return abs(vChecksum);
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

//        foreach (QString vPath, vImagesPath) { // wersja finalna:
//            QImage vImage(vPath);
//            QByteArray vData = ConvertImageToByteArray(vImage);

//            int16_t vFileChecksum = CalculateFileDataChecksum(vData);
//            QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
//            WriteMessage(vChecksumByte);
//            WaitForChangeStatus();
//            ManageData(vData);
//        }

        QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
QStringList vPicturesLocation = QStandardPaths::standardLocations(
                                 QStandardPaths::PicturesLocation);

QString vPath = vPicturesLocation.at(0);
QDir vDir(vPath);
QStringList vAllFiles =  vDir.entryList(QDir::Files);
       foreach (QString location, vAllFiles) {
         qDebug() << "file:" << location;
       }
    vPath += "/a.jpg";

qDebug() << "Koncowy path:" << vPath;
QImage vImageToSend(vPath);

QBuffer vBuffer;

QImageWriter vWriter(&vBuffer, "JPG");
vWriter.write(vImageToSend);

QByteArray vData = vBuffer.data();

uint16_t vFileChecksum = CalculateFileDataChecksum(vData);
  qDebug() <<"vChecksum one\n"<< vFileChecksum;
            QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
            qDebug() <<"vChecksumByte\n"<< vChecksumByte;
            WriteMessage(vChecksumByte);
            WaitForChangeStatus();
            ManageData(vData);

//WriteData(vData);
//       wersja 1 testowa 1 obrazek sprawdzenie i  wysłanie:
//       QImage image(vImagesPath);// lub .jpeg
//		 qDebug() << "size image in update serv photo func:" << image.size();
//		 QByteArray vData = ConvertImageToByteArray(image);
//		 int16_t vFileChecksum = CalculateFileDataChecksum(vData);
//		 QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
//		 WriteMessage(vChecksumByte);
//		 WaitForChangeStatus();
//         ManageData(vData);
}
