#include "CClient.h"

#include <stdio.h> // convert array to int function
#include <ctype.h> // isdigit function
#include <QDebug>
#include <QFile>

CClient::CClient(QObject *aParent) :

		QObject(aParent),
		mSocket(NULL),
		mReceiveBuffer(NULL),
		mDataSize(NULL),
		mReceiveDataMode(Mode_Receive_File_Data),
		mMessageSize(0),
		mReceiveByteCnt(0),
		mReceiveFrameNOKCnt(0),
		mReceiveFrameFaultCnt(0) {
}

CClient::~CClient() {
		Disconnected();
}

void CClient::Connect(QTcpSocket *aSocket) {
		if (aSocket) {
				const char *vMessage = "Klient połączony. Nasłuchiwanie serwera wyłączone";
				qDebug() << vMessage;

				emit MessageStatus(vMessage, 2200);

				mSocket = aSocket;

				mDataSize = new qint32(0);
				mReceiveBuffer = new QByteArray();

				ConnectSocketSignals();

		} else {
				const char *vMessage = "Nie można połączyć";
				qDebug() << vMessage;

				emit MessageStatus(vMessage, 2200);

				emit mSocket->error();
		}
}

QTcpSocket *CClient::GetSocket() const {
		return mSocket;
}

void CClient::NewData() {
		while (mSocket->bytesAvailable() > 0) {
				QByteArray vData = mSocket->readAll();
				mReceiveBuffer->append(vData);

				for (int i = 0; i < vData.length(); i++) {

						char vTargetSign = vData[i];

						switch (vTargetSign) {

								case '>':					// początek komunikatu "suma pliku"
										mReceiveDataMode = Mode_Receive_File_CheckSum;
										mReceiveByteCnt = 0;
										break;

								default:
										break;
						}

						RouteData(vTargetSign);
				}
		}
}

void CClient::RouteData(char aData) {
		switch (mReceiveDataMode) {

				case Mode_Receive_File_Data : {
						ServeFileData();
						break;
				}

				case Mode_Receive_File_CheckSum: {
						mMessageClntFileChecksum[mReceiveByteCnt] = aData;
						mReceiveByteCnt++;

						if (mReceiveByteCnt >= 1023) { // Prevent buffer overflow
								mReceiveByteCnt = 0;
						}

						// lub CR LF 0x0A 0x0D
						if (aData == '<') {		    // koniec komunikatu "suma pliku"
								mMessageSize = mReceiveByteCnt;
								mReceiveByteCnt = 0;
								ServeReceivedMessage();
								mReceiveDataMode = Mode_Receive_File_Data;
						}

						break;
				}

				default:
						break;
		}
}

void CClient::ServeReceivedMessage() {
		if (!HasMessageCorrectFormat(mMessageClntFileChecksum)) {
				qDebug() << ":IncorrectMessageFormat: ";
				++mReceiveFrameNOKCnt;
				return;
		}

		//		if (!HasMessageCorrectChecksum(*mReceiveBuffer)) {
		//				qDebug() << ":IncorrectMessageChecksum: ";
		//				++mReceiveFrameFaultCnt;
		//				return;
		//		}
		QString vNumAsString;

		// wyodrębnienie liczyby-string z tablicy i konwersja na int
		// wersja 1:
		for (int i = 0; i < mMessageSize; i++) {
				if (isdigit(mMessageClntFileChecksum[i])) {
						vNumAsString.append(mMessageClntFileChecksum[i]);
				}
		}

		int vValidNum = vNumAsString.toInt();
		mReceiveBuffer->remove(0, mMessageSize);

		QByteArray vDataToSend = vNumAsString.toUtf8(); //?
		emit ReadData(vNumAsString.toUtf8());
		qDebug() << vValidNum;
		// wersja alternatywna:
		//		std::string vStringFromArray(mMessageClntFileChecksum);
		//		std::string vNumAsString = vStringFromArray.substr(1, mMessageSize-2);
		//		int vNum = QString::fromStdString(vNumAsString).toInt();

		///@todo //  BYTE* vAsciiDataBegin = aData+2;  // 2 bytes of header
		//  int vAsciiMessageDataLength = aLen-6;  // 2 bytes of header, 2 of checksum, CR, LF
		//  ConvertHexAsciiToBinary(vAsciiDataBegin, vAsciiMessageDataLength, mBinaryMessageData);

		//  ++mReceiveFrameOKCnt;
		//  RouteMessage(mBinaryMessageData, vAsciiMessageDataLength/2, aData);
}

bool CClient::HasMessageCorrectFormat(char *aMessage) {
		bool vCorrect = true;

		int vChecksumLength = mMessageSize - 2; // 2 bytes of header, CR, LF
		qDebug() << "mes:" << aMessage;
		qDebug() << mMessageSize << "messize";
		if (aMessage[0] != '>') {  // begin character
				vCorrect =  false;
				qDebug() << "a" << aMessage[0] ;
		} else if ((aMessage[mMessageSize - 1] != ('<'))) {
				vCorrect = false;
				qDebug() << "c";
				qDebug() << aMessage[mMessageSize - 1];
		} else {
				for (int i = 1; i < vChecksumLength + 1; ++i) {
						if (!isxdigit(aMessage[i])) {
								vCorrect = false;
								qDebug() << "d";
						}
				}
		}

		return vCorrect;
}

void CClient::ServeFileData() {
		int32_t vCurrentSize = *mDataSize;

		while ((vCurrentSize == 0 && mReceiveBuffer->size() >= 4) ||
						(vCurrentSize > 0 &&
						 mReceiveBuffer->size() >= vCurrentSize)) { //While can process data, process it
				if (vCurrentSize == 0 &&
								mReceiveBuffer->size() >=
								4) { //if size of data has received completely, then store it on our global variable
						vCurrentSize = ByteArrayToInt(mReceiveBuffer->left(4)); // było mid(0,4)
						*mDataSize = vCurrentSize;
						mReceiveBuffer->remove(0, 4);
				}

				if (vCurrentSize > 0 && mReceiveBuffer->size() >=
								vCurrentSize) { // If data has received completely, then emit our SIGNAL with the data
						QByteArray vData = mReceiveBuffer->left(
																	 vCurrentSize);  // było mid(0,vcurrentsize )
						qDebug() << *mReceiveBuffer << "sex" << vData;
						mReceiveBuffer->remove(0, vCurrentSize);
						qDebug() << *mReceiveBuffer;
						vCurrentSize = 0;
						*mDataSize = vCurrentSize;

						qDebug() << "suma:" <<	CalculateMessageChecksum(vData);

						QFile vFile("/home/mmichniewski/b.txt");//pobranyPies.jpg");

						if (!vFile.open(QIODevice::WriteOnly)) {
								qDebug() << "Nie można otworzyć pliku";
						};

						QDataStream out(&vFile);

						out << vData;

						vFile.close();

						qDebug() << vData;

						//const char *vMessage = "Odebrano dane : ";

						//ResponeToClient(vMessage, vData);

						emit ReadData(vData);;
				}
		}
}

bool CClient::HasMessageCorrectChecksum(QByteArray aData) {
		int vAsciiMessageHeaderPlusDataLength = aData.length() -
																						4; // 4, because 2 bytes of checksum, CR and LF

		QByteArray vAsciiChecksumBegin = aData;
		vAsciiChecksumBegin += vAsciiMessageHeaderPlusDataLength;

		//    uint8_t vExpectedChecksum = 0;
		//    ConvertHexAsciiToBinary(vAsciiChecksumBegin, 2/*checksum length*/, &vExpectedChecksum);

		//    uint8_t vCalculatedChecksum =
		//        CalculateMessageChecksum(aData, vAsciiMessageHeaderPlusDataLength);

		//    return vCalculatedChecksum == vExpectedChecksum;
		return 0; ///@todo
}

uint8_t CClient::CalculateMessageChecksum(QByteArray aData) {
		uint8_t vSum = 0;

		for (int i = 0; i < aData.length(); ++i) {
				vSum += aData[i];
		}

		return vSum;
}

int32_t CClient::ByteArrayToInt(QByteArray aData) {
		int32_t vResult;
		QDataStream vData(&aData, QIODevice::ReadWrite);
		vData >> vResult;
		return vResult;
}

void CClient::ConnectSocketSignals() {
		QObject::connect(mSocket, SIGNAL(disconnected()), this, SLOT(Disconnected()),
										 Qt::DirectConnection);

		QObject::connect(mSocket, SIGNAL(readyRead()), this, SLOT(NewData()),
										 Qt::DirectConnection);
}

void CClient::Disconnected() {
		const char *vMessage = "Rozłączono";
		qDebug() << vMessage;

		emit MessageStatus(vMessage, 2200);
		emit Disconnect();

		mSocket->deleteLater();
		delete mReceiveBuffer;
		delete mDataSize;
}

void CClient::ResponeToClient(const char *aMessage, QByteArray aData) {
		mSocket->write(aMessage);
		mSocket->write(aData);
}
