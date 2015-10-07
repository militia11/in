#include "CClient.h"
#include <QImage>
#include <QImageWriter>
static inline QByteArray IntToArray(int32_t aSource);

CClient::CClient(QObject *aParent) : QObject(aParent) {
    mSocket = new QTcpSocket(this);
    mReceiveBuffer = 0;
    mActualData = 0;
    connect( mSocket, SIGNAL(readyRead()),
             this, SLOT(ReadData()), Qt::DirectConnection );
}

void CClient::ReadData() {
    //while (mSocket->bytesAvailable() > 0) {
    QByteArray vMessageData = mSocket->readAll();
    qDebug() << vMessageData;

    if (vMessageData == QByteArray("SEND")) { // if wiadomość równa 'SEND'
        //writeData(mActualData); // wyślij plik(jego dane binarne) aktualnie sprawdzanego pliku
        //(sprawdzanej jego sumy)

        //	int v = CalculateMessageChecksum(vData);
        //	qDebug() << "suma->" << v;

        WriteData(mSendBuffer);
    }
}

bool CClient::ConnectToHost(QString aHost) {
    mSocket->connectToHost(aHost, 1234);
    bool vConnected = mSocket->waitForConnected(90000);

    if (vConnected == false) {
        qDebug() << mSocket->error();
    }

    return vConnected;
}

void CClient::ConvertBinaryToHexAscii(const char *aData, int aLen,
                                      char *aTarget) {
    char vBuffer[3];

    for (int i = 0; i < aLen; ++i) {
        snprintf(vBuffer, 3, "%02X", aData[i]);
        aTarget[2 * i] = vBuffer[0];
        aTarget[2 * i + 1] = vBuffer[1];
    }
}

bool CClient::PrepareMessageData() {
    // narazie tak:
    QImage vImage = QImage ("/home/mmichniewski/b.jpeg", "JPEG");
    QBuffer vBuffer;

    QImageWriter vWriter(&vBuffer, "JPEG");
    vWriter.write(vImage);

    QByteArray vData = vBuffer.data();

    ConvertBinaryToHexAscii(vData, vData.length(), mSendBuffer + 2);

    //								// CRC
    //								uint8_t vChecksum = CalculateMessageChecksum(mSendBuffer, 2+2*aLen);
    //								ConvertBinaryToHexAscii(&vChecksum, 1, mSendBuffer+2+aLen*2);

    //								// footer
    //								mSendBuffer[2+2+2*aLen] = 0x0D; // CR
    //								mSendBuffer[2+2+2*aLen+1] = 0x0A; // LF

    //								return 2*aLen + 6;
    return true;
}

bool CClient::WriteData(QByteArray aData) {
    if (mSocket->state() == QAbstractSocket::ConnectedState) {
        mSocket->write(IntToArray(aData.length())); //write size of data
        mSocket->write(aData); //write the data itself
        return mSocket->waitForBytesWritten();
    } else {
        return false;
    }
}

bool CClient::WriteMessage(QByteArray aData) {
    if (mSocket->state() == QAbstractSocket::ConnectedState) {
        mSocket->write(aData); //write the data itself
        return true;// mSocket->waitForBytesWritten();
    } else {
        return false;
    }

    //			// if (socket->state() == QAbstractSocket::ConnectedState) {
    //					 //	socket->write(IntToArray(data.size())); //write size of data

    //					 aData.insert(0, '>');
    //					 qDebug()<< aData;
    //					 u_int8_t vMessageCheckSum = CalculateMessageChecksum(aData);

    //					 qDebug()<< aData;
    //					 socket->write(aData); //write the data itself
    //					 return socket->waitForBytesWritten();
    //		//    } else {
    //		//        return false;
    //		//    }
}

uint8_t CClient::CalculateMessageChecksum(QByteArray aData) {
    uint8_t vChecksum = 0;

    for (int i = 0; i < aData.length(); ++i) {
        vChecksum += aData[i];
    }

    return vChecksum;
}
QByteArray IntToArray(int32_t
                      aSource) { //Use qint32 to ensure that the number have 4 bytes
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray vTemporaryData;
    QDataStream vResult(&vTemporaryData, QIODevice::ReadWrite);
    vResult << aSource;
    return vTemporaryData;
}
