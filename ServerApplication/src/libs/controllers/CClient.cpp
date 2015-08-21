#include "CClient.h"
#include <QDebug>

CClient::CClient(QObject *aParent) :

		QObject(aParent),
		mSocket(NULL),
		mReceiveBuffer(0),
		mReceiveByteCnt(0),
		mReceiveFrameNOKCnt(0),
		mReceiveFrameFaultCnt(0) {
		mReceiveDataMode = Mode_UnknownData;
}

CClient::~CClient() {
		Disconnected();
		//i zrobic  mfiledata delete jakby jakis new był
}

void CClient::Connect(QTcpSocket *aSocket) {
		if (aSocket) {
				const char *vMessage = "Klient połączony. Nasłuchiwanie serwera wyłączone";
				qDebug() << vMessage;

				emit MessageStatus(vMessage, 2200);

				mSocket = aSocket;

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
		QByteArray vData = mSocket->readAll();

		QDataStream in(vData);    // read the data serialized from the file
		QString str;
		in >> str;           // extract "the answer is" and 42

		qDebug() << str << "du" ;
		//		if (!vData.isEmpty()) { // nie wiem czy ten if ma sens?

		//				for (int i = 0; i < vData.length(); i++) {

		//						char vTargetData = vData[i];

		//						switch (vTargetData) {

		//								case '>':
		//										mReceiveDataMode = Mode_Receive_Files;
		//										mReceiveByteCnt = 0;
		//										break;

		//								case '^':
		//										mReceiveDataMode = Mode_Receive_FileList;
		//										mReceiveByteCnt = 0;
		//										break;

		//								default:
		//										break;
		//						}

		//						if (mReceiveByteCnt >= 1023) { // Prevent buffer overflow
		//								mReceiveByteCnt = 0;
		//						}

		//						char vRouteTarget = vData[i];

		//						//if (vData[i].operator != (0)) { // pomyśleć zmianę tego
		//						mReceiveBuffer[mReceiveByteCnt] = vData[i];
		//						++mReceiveByteCnt;
		//						//}

		//						RouteData(mReceiveDataMode, vRouteTarget);
		//				}

						const char *vMessage = "Odebrano dane : ";
						ResponeToClient(vMessage, vData);
		//		}

		emit ReadData(vData);
}


void CClient::RouteData(ReceiveDataMode mReceiveDataMode, char aData) {
		switch (mReceiveDataMode) {

				case Mode_Receive_FileList:
						///@todo
						break;

				case Mode_Receive_Files:
						if (aData == 0x0A) {
								ServeReceivedMessage(); //, mReceiveByteCnt
								mReceiveByteCnt = 0;
						}

						break;

				case Mode_UnknownData:
						break;

				default:
						break;
		}
}

void CClient::ServeReceivedMessage() {
		if (!HasMessageCorrectFormat(mReceiveBuffer)) {
				qDebug() << ":IncorrectMessageFormat: ";
				++mReceiveFrameNOKCnt;
				return;
		}

		if (!HasMessageCorrectChecksum(mReceiveBuffer)) {
				qDebug() << ":IncorrectMessageChecksum: ";
				++mReceiveFrameFaultCnt;
				return;
		}
///@todo
		//  BYTE* vAsciiDataBegin = aData+2;  // 2 bytes of header
		//  int vAsciiMessageDataLength = aLen-6;  // 2 bytes of header, 2 of checksum, CR, LF
		//  ConvertHexAsciiToBinary(vAsciiDataBegin, vAsciiMessageDataLength, mBinaryMessageData);

		//  ++mReceiveFrameOKCnt;
		//  RouteMessage(mBinaryMessageData, vAsciiMessageDataLength/2, aData);
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
}

void CClient::ResponeToClient(const char *aMessage, QByteArray aData) {
		mSocket->write(aMessage);
		mSocket->write(aData);
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

bool CClient::HasMessageCorrectFormat(QByteArray aData) {
		bool vCorrect = true;
		int vDataLen = aData.length();

		int vDataAndChecksumLength = vDataLen - 4; // 2 bytes of header, CR, LF

		if (aData[0] != '>') {  // begin character
				vCorrect =  false;
				qDebug() << "a";
		} else if (aData[1] != 'L' && aData[1] != 'D') {
				vCorrect = false;
				qDebug() << "b";
				//				for(int i=0;i<aData.length();i++){
				//					qDebug() << "bi";
				//					qDebug() << aData[i];
				//				}
				qDebug() << aData[1];
		} else if ((aData[vDataLen - 2].operator != (0x0D)) ||
							 (aData[vDataLen - 1].operator != (0x0A))) { // CR LF
				vCorrect = false;
				qDebug() << "c";
				qDebug() << aData[vDataLen - 2];
				qDebug() << aData[vDataLen - 1];
		} else {
				for (int i = 2; i < vDataAndChecksumLength; ++i) {
						if (!isxdigit(aData[i])) {
								vCorrect = false;
								qDebug() << "d";
						}
				}
		}

		return vCorrect;
}

