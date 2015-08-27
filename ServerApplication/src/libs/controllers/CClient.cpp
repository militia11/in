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

						// Zabezpieczenie przeładowania buforu
						if (mReceiveByteCnt >= 1023) {
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
				const char *vMessage = "Nieprawidłowy format wiadomości";
				MessageStatus(vMessage, 2200);
				qDebug() << vMessage;
				++mReceiveFrameNOKCnt;
				return;
		}

		// wyodrębnienie liczyby-string z tablicy i konwersja na int
		// wersja 1:
		QString vNumAsString;

		for (int i = 0; i < mMessageSize; i++) {
				if (isdigit(mMessageClntFileChecksum[i])) {
						vNumAsString.append(mMessageClntFileChecksum[i]);
				}
		}

		int vValidNum = vNumAsString.toInt();

		// wersja alternatywna:
		//		std::string vStringFromArray(mMessageClntFileChecksum);
		//		std::string vNumAsString = vStringFromArray.substr(1, mMessageSize-2);
		//		int vNum = QString::fromStdString(vNumAsString).toInt();

		mReceiveBuffer->remove(0, mMessageSize);

		QByteArray vDataToSend = vNumAsString.toUtf8(); //?
		emit ReadData(vNumAsString.toUtf8());

		qDebug() << vValidNum;
}

bool CClient::HasMessageCorrectFormat(char *aMessage) {
		bool vCorrect = true;
		int vChecksumLength = mMessageSize - 2; // 2 bajty znaki '>' i '<'

		if (aMessage[0] != '>') {  // początek komunikatu
				vCorrect =  false;
		} else if ((aMessage[mMessageSize - 1] != ('<'))) {
				vCorrect = false;

		} else {
				for (int i = 1; i < vChecksumLength + 1; ++i) {
						if (!isxdigit(aMessage[i])) {
								vCorrect = false;
						}
				}
		}

		return vCorrect;
}

void CClient::ServeFileData() {
		int32_t vCurrentSize = *mDataSize;

		// Jeśli można pobierać dane pobieraj
		while ((vCurrentSize == 0 && mReceiveBuffer->size() >= 4) ||
						(vCurrentSize > 0 &&
						 mReceiveBuffer->size() >= vCurrentSize)) {

				if (vCurrentSize == 0 &&
								mReceiveBuffer->size() >=
								4) { //if size of data has received completely, then store it on our global variable
						vCurrentSize = ByteArrayToInt(mReceiveBuffer->left(4));
						*mDataSize = vCurrentSize;
						mReceiveBuffer->remove(0, 4);
				}

				if (vCurrentSize > 0 && mReceiveBuffer->size() >=
								vCurrentSize) { // If data has received completely, then emit our SIGNAL with the data
						QByteArray vData = mReceiveBuffer->left(
																	 vCurrentSize);  // było mid(0,vcurrentsize )

						mReceiveBuffer->remove(0, vCurrentSize);
						vCurrentSize = 0;
						*mDataSize = vCurrentSize;

						qDebug() << "suma:" <<	CalculateFileDataChecksum(vData);

						QFile vFile("/home/mmichniewski/b.txt");//pobranyPies.jpg");

						if (!vFile.open(QIODevice::WriteOnly)) {
								const char *vMessage = "Nie można otworzyć pliku";
								MessageStatus(vMessage, 2200);
								qDebug() << vMessage;
						};

						QDataStream out(&vFile);

						out << vData;

						vFile.close();

						const char *vMessage = "Odebrano dane : ";
						ResponeToClient(vMessage, vData);

						emit ReadData(vData);
				}
		}
}

uint8_t CClient::CalculateFileDataChecksum(QByteArray aData) {
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
