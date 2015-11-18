#include "CClient.h"

#include<stdlib.h>
//#include<time.h>
#include <cstdlib>
#include <QBuffer>
#include <QImage>
#include <QImageWriter>
#include <unistd.h>
#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlib/CQTcpSocketMock.h"

extern CRepository gRepository;

CClient::CClient(QTcpSocket *aSocket) : mSocket(aSocket){
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
				qDebug() << vMessageData;

				if (vMessageData ==
								QByteArray("NEW FILE")) { // lub SEND, ARCHIVE jak nie będzie działac
						mSendFile = true;
						//alternatywa wysylanie tu danych binarnych lecz utrudnienia
						//actual trzeba by dawac i inne opoznienia
						//WriteData(mActualData); // wyślij dane binarne aktualnie sprawdzanego pliku
						// po sprawdzeniu jego sumy przez serwer
				}
    }
}

bool CClient::ConnectToHost(QString aHost) {
    mSocket->connectToHost(aHost, mPortNumber);
    bool vConnected = mSocket->waitForConnected();

		if (vConnected == false) {
			qDebug()<<mSocket->error();
        throw mSocket->error();///@todo zlapanie
		}

		return vConnected;
}

QByteArray CClient::ConvertImageToByteArray(const QImage &aImage) {
		QBuffer vBuffer;

		QImageWriter vWriter(&vBuffer, "JPG");
		vWriter.write(aImage);  // unikniecie vWriter.write(*(*vIterator));
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
		QList<QImage> vImagesList = gRepository.GetImages();

		for (QList<QImage>::iterator vIterator = vImagesList.begin();
						vIterator != vImagesList.end(); ++vIterator) {
				// lub mActualData = dół i wysyłanie w ReadData choć lepiej tu
				QByteArray vData = ConvertImageToByteArray(*vIterator);
				int16_t vFileChecksum = CalculateFileDataChecksum(vData);
				QByteArray vChecksumByte = PrepareMessageData(vFileChecksum);
				WriteMessage(vChecksumByte);
				sleep(3); // this->WaitForResult();

				if (mSendFile) {
						WriteData(vData);
						mSendFile = false;
				}
		}
}
