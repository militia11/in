#include "CClient.h"

#include <stdio.h> // convert array to int

#include <QDebug>
#include <QFile>

CClient::CClient(QObject *aParent) :

		QObject(aParent),
		mSocket(NULL),
		mReceiveBuffer(NULL),
		mSize(NULL),
		mReceiveByteCnt(0),
		mReceiveFrameNOKCnt(0),
		s(0),
		mReceiveFrameFaultCnt(0) {
		mReceiveDataMode = Mode_Receive_File_Data;
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

				mSize = new qint32(0);
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
				qDebug() << "size" << mReceiveBuffer->length() << "x";

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
						qDebug() << "jestem w route case ---file data---";
						ServeFileData();
						break;
				}

				case Mode_Receive_File_CheckSum: {
						qDebug() << "jestem w route case ---chcks---";

						mMessageClntFileChecksum[mReceiveByteCnt] = aData;
						mReceiveByteCnt++;

						if (mReceiveByteCnt >= 1023) { // Prevent buffer overflow
								mReceiveByteCnt = 0;
						}

						if (aData == '<') {		//0x0A
								qDebug() << "jestem w routeData  w case chcks w if";
								s = mReceiveByteCnt;
								mReceiveByteCnt = 0;
								ServeReceivedMessage();
								//mReceiveDataMode = Mode_Receive_File_Data; //mReceiveByteCnt = 0;
						}

						break;
				}

				default:
						break;
		}
}

void CClient::ServeReceivedMessage() {
		qDebug() << "serveee len" << s;

		std::string str(mMessageClntFileChecksum);
		std::string res = str.substr(1,s-2);
		qDebug() << "kup" << QString::fromStdString(res);
		for (int i = 0; i < s; i++) {
				qDebug() << "medd" << mMessageClntFileChecksum[i];
		}

		if (!HasMessageCorrectFormat(*mReceiveBuffer)) {
				qDebug() << ":IncorrectMessageFormat: ";
				++mReceiveFrameNOKCnt;
				return;
		}

		//		if (!HasMessageCorrectChecksum(*mReceiveBuffer)) {
		//				qDebug() << ":IncorrectMessageChecksum: ";
		//				++mReceiveFrameFaultCnt;
		//				return;
		//		}
		///@todo //  BYTE* vAsciiDataBegin = aData+2;  // 2 bytes of header
		//  int vAsciiMessageDataLength = aLen-6;  // 2 bytes of header, 2 of checksum, CR, LF
		//  ConvertHexAsciiToBinary(vAsciiDataBegin, vAsciiMessageDataLength, mBinaryMessageData);

		//  ++mReceiveFrameOKCnt;
		//  RouteMessage(mBinaryMessageData, vAsciiMessageDataLength/2, aData);
}

bool CClient::HasMessageCorrectFormat(QByteArray aData) {
		bool vCorrect = true;
		int vDataLen = aData.length();

		int vChecksumLength = vDataLen - 2; // 2 bytes of header, CR, LF
		qDebug() << "d:" << aData;
		qDebug() 	 << "len:" << aData.length();

		if (aData[0] != '>') {  // begin character
				vCorrect =  false;
				qDebug() << "a" << aData[0] << "len" << aData.length();
		} else if ((aData[vDataLen - 1].operator != ('<'))) { // CR LF
				vCorrect = false;
				qDebug() << "c";
				qDebug() << aData[vDataLen - 1];
		} else {
				for (int i = 1; i < vChecksumLength; ++i) {
						if (!isxdigit(aData[i])) {
								vCorrect = false;
								qDebug() << "d";
						}
				}
		}

		return vCorrect;
}

void CClient::ServeFileData() {
		int32_t vCurrentSize = *mSize;

		while ((vCurrentSize == 0 && mReceiveBuffer->size() >= 4) ||
						(vCurrentSize > 0 &&
						 mReceiveBuffer->size() >= vCurrentSize)) { //While can process data, process it
				if (vCurrentSize == 0 &&
								mReceiveBuffer->size() >=
								4) { //if size of data has received completely, then store it on our global variable
						vCurrentSize = ByteArrayToInt(mReceiveBuffer->left(4)); // było mid(0,4)
						*mSize = vCurrentSize;
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
						*mSize = vCurrentSize;

						qDebug() << "suma:" <<	CalculateMessageChecksum(vData);

						QFile vFile("/home/mmichniewski/b.txt");//pobranyPies.jpg");

						if (!vFile.open(QIODevice::WriteOnly)) {
								qDebug() << "Nie można otworzyć pliku";
						};

						QDataStream out(&vFile);

						out << vData;

						vFile.close();

						qDebug() << vData;

						const char *vMessage = "Odebrano dane : ";

						ResponeToClient(vMessage, vData);

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
		delete mSize;
}

void CClient::ResponeToClient(const char *aMessage, QByteArray aData) {
		mSocket->write(aMessage);
		mSocket->write(aData);
}
