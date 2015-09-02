#include "CClient.h"
#include "libs/dao/CRepository.h"

#include <stdio.h> // convert array to int function
#include <ctype.h> // isdigit function
#include <QDebug>
#include <QFile>

extern CRepository gRepository;

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

void CClient::ConvertHexAsciiToBinary(const char *aData, int aLen,
																			char *aTarget) {
		for (int i = 0; i < aLen - 1; i += 2) {
				char hex[3] = {aData[i], aData[i + 1], 0x00};
				aTarget[i / 2] = static_cast<char>(strtol(hex, NULL, 16));
		}
}

void CClient::ConvertBinaryToHexAscii(const char *aData, int aLen,
																			char *aTarget) {
		char buffer[3];

		for (int i = 0; i < aLen; ++i) {
				snprintf(buffer, 3, "%02X", aData[i]);
				aTarget[2 * i] = buffer[0];
				aTarget[2 * i + 1] = buffer[1];
		}
}

void CClient::NewData() {

		while (mSocket->bytesAvailable() > 0) {
				QByteArray vData = mSocket->readAll();
				mReceiveBuffer->append(vData);
				qDebug() << "datanew" << vData.size();


				for (int i = 0; i < vData.length(); i++) {
						char vTargetSign = vData[i];

						switch (vTargetSign) {

								case '>': {					// początek komunikatu "suma pliku"

										char vNextChar = vData[i + 1];

										if (vNextChar == '>') {
												mReceiveDataMode = Mode_Receive_File_CheckSum;
												//mReceiveByteCnt = 0;
										}

										break;
								}

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
						ServeReceivedFileData();
						break;
				}

				case Mode_Receive_File_CheckSum: {
						mMessageClntFileChecksum[mReceiveByteCnt] = aData;
						mReceiveByteCnt++;

						// Zabezpieczenie przeładowania buforu
						if (mReceiveByteCnt >= 1023) {
								mReceiveByteCnt = 0;
						}

						if (aData == '<') {		    // koniec komunikatu "suma pliku"
								mReceiveDataMode = Mode_Receive_File_Data;
								mMessageSize = mReceiveByteCnt;
								//mReceiveBuffer->clear();
								//mMessageClntFileChecksum.
								mReceiveBuffer->clear();// ->remove(0, mMessageSize);
								mReceiveByteCnt = 0;
								ServeReceivedMessage();
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

		int vChecksum = ConverMessageArraytToInt();

		CChecksumList *vChecksumList = gRepository.GetChecksumList();
		bool vIsChecksumInSrv = vChecksumList->CheckFileChecksum(vChecksum);
		qDebug() << vIsChecksumInSrv;

		mReceiveBuffer->clear();
		delete mDataSize;
		mDataSize = 0;
		mDataSize  = new qint32(0);
		mMessageSize = 0;
		mReceiveByteCnt = 0;

		if (!vIsChecksumInSrv) {
				QByteArray vMessage("SEND");
				ResponeToClient(vMessage);
				//				i klient zapamietuje co wysylal jaka sume wiec ten plik wysyla

				//				alternatywa:
				//        QString vClientMessage = PrepareSendingToClientMessage(vChecksum);
				//        ResponeToClient(vClientMessage);
    }
}

bool CClient::HasMessageCorrectFormat(char *aMessage) {
		bool vCorrect = true;
		int vChecksumLength = mMessageSize - 3; // 2 bajty znaki '>' i '<'
		qDebug() << "mes" << aMessage << sizeof(aMessage);

		if (aMessage[0] != '>') {  // początek komunikatu
				vCorrect =  false;
				qDebug() << "a";
		} else if ((aMessage[mMessageSize - 1] != ('<'))) {
				vCorrect = false;
				qDebug() << "b";
		} else {
				for (int i = 2; i < vChecksumLength + 2; ++i) {
						if (!isxdigit(aMessage[i])) {
								vCorrect = false;
								qDebug() << "c";
								return vCorrect;
						}
				}
		}

		return vCorrect;
}

void CClient::ServeReceivedFileData() {
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
						QByteArray vData = mReceiveBuffer->left(vCurrentSize);

						mReceiveBuffer->remove(0, vCurrentSize);
						vCurrentSize = 0;
						*mDataSize = vCurrentSize;

						u_int8_t vChecksum =	CalculateFileDataChecksum(vData);

						CAddToDBTransaction AddToDBTransaction(vData, vData.size(), vChecksum);
						AddToDBTransaction.Execute();

						//						CRetrieveFromDBTransaction vRetrieveTransaction(221);
						//						vRetrieveTransaction.Execute();
						//						QByteArray vRetrieveData =  vRetrieveTransaction.getData();

						//						const char *vMessage = "Odebrano dane : ";
						//						ResponeToClient(vMessage, vData);

						emit ReadData(vData);///@todo odznaczyc kom na koniec sprawdzic co i jak
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
		QObject::connect(mSocket, SIGNAL(disconnected()), this,
										 SLOT(Disconnected()), Qt::DirectConnection);

		QObject::connect(mSocket, SIGNAL(readyRead()), this,
										 SLOT(NewData()), Qt::DirectConnection);
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

QString CClient::PrepareSendingToClientMessage(int aChecksum) {
		QString vResultMessage(">>");
		vResultMessage.append(aChecksum);
		vResultMessage.append("<<");
		return vResultMessage;
}

int CClient::ConverMessageArraytToInt() {
		// wyodrębnienie liczyby-stringa z tablicy i konwersja na int
		// wersja 1:

		QString vNumAsString;

		for (int i = 0; i < mMessageSize; i++) {
				if (isdigit(mMessageClntFileChecksum[i])) {
						vNumAsString.append(mMessageClntFileChecksum[i]);
				}
		}

		return vNumAsString.toInt();

		// wersja alternatywna:
		//		std::string vStringFromArray(mMessageClntFileChecksum);
		//		std::string vNumAsString = vStringFromArray.substr(2, mMessageSize-4);
		//		int vNum = QString::fromStdString(vNumAsString).toInt();
}

void CClient::ResponeToClient(QByteArray aData) {
		mSocket->write(aData);
}
