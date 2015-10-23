#include "CClient.h"

#include<stdlib.h>
//#include<time.h>
#include <cstdlib>
#include <QBuffer>
#include <QImage>
#include <QImageWriter>
#include <unistd.h> // unix
//#include "windows.h" // duze Sleep windows
#include "libs/dao/CRepository.h"

extern CRepository gRepository;

CClient::CClient() {
    mSocket = new QTcpSocket(this);

    mReceiveBuffer = 0;
    mFileToSend = false;

		QObject::connect(mSocket, SIGNAL(readyRead()),
            this, SLOT(ReadData()), Qt::DirectConnection);
    PrepareMessageData(384);
}

CClient::~CClient() {
    delete  mSocket;
    mSocket = 0;

    delete mReceiveBuffer;
    mReceiveBuffer = 0;
}

void CClient::ReadData() {
    while (mSocket->bytesAvailable() > 0) {
        QByteArray vMessageData = mSocket->readAll();
        qDebug() << vMessageData;

        if (vMessageData ==
								QByteArray("ARCHIVE")) { // lub SEND jak nie będzie działac
            mFileToSend = true;
            //alternatywa wysylanie tu danych binarnych lecz utrudnienia
            //actual trzeba by dawac i inne opoznienia
            //WriteData(mActualData); // wyślij dane binarne aktualnie sprawdzanego pliku
            // po sprawdzeniu jego sumy przez serwer
        }
    }
}

bool CClient::ConnectToHost(QString aHost) {
    mSocket->connectToHost(aHost, 1234);
    bool vConnected = mSocket->waitForConnected(
                          90000); ///@todo komentarz skad taka liczba

    if (vConnected == false) {
        qDebug() << mSocket->error();
    }

    return vConnected;
}

QByteArray CClient::ConvertImageToByteArray(QImage aImage) {
    QBuffer vBuffer;

    QImageWriter vWriter(&vBuffer, "JPG");
    vWriter.write(aImage);  // unikniecie vWriter.write(*(*vIterator));
    return vBuffer.data();
}

QByteArray CClient::PrepareMessageData(int16_t aChecksum) {
    const char *vChecksumAsString = qPrintable(QString::number(aChecksum));
    QByteArray vData(vChecksumAsString);
    vData.insert(0, '>');
    vData.insert(1, '>');
    vData.append("<");

    return vData;
}

bool CClient::WriteData(QByteArray aData) {
    if (mSocket->state() == QAbstractSocket::ConnectedState) {
        mSocket->write(IntToArray(aData.length()));
        mSocket->write(aData);

        return mSocket->waitForBytesWritten();
    } else {

        return false;
    }
}

bool CClient::WriteMessage(QByteArray aData) {
    if (mSocket->state() == QAbstractSocket::ConnectedState) {
        mSocket->write(aData);

        return mSocket->waitForBytesWritten();
    } else {

        return false;
    }
}

int16_t CClient::CalculateFileDataChecksum(QByteArray aData) {
    int16_t vChecksum = 0;

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

        if (mFileToSend) {
            WriteData(vData);
            mFileToSend = false;
        }
    }
}

