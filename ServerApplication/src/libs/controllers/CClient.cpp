#include "CClient.h"
#include <QDebug>
#include <QFile>

CClient::CClient(QObject *aParent) :

		QObject(aParent),
		mSocket(NULL),
		mBuffer(NULL),
		mSize(NULL),
		mReceiveBuffer(0),
		mReceiveByteCnt(0),
		mReceiveFrameNOKCnt(0),
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
				mBuffer = new QByteArray();

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
		//int32_t vCurrentSize = *mSize;

		while (mSocket->bytesAvailable() > 0) {
				QByteArray vData = mSocket->readAll();
				mBuffer->append(vData); //przeniesc nizej
				qDebug() << "11";

				for (int i = 0; i < vData.length(); i++) {

						char vTargetData = vData[i];

						switch (vTargetData) {
								case '>':
										mReceiveDataMode = Mode_Receive_File_CheckSum;
										mReceiveByteCnt = 0;
										break;

								case '^':
										mReceiveDataMode = Mode_Receive_File_Data;
										mReceiveByteCnt = 0;
										break;

								default:
										break;
						}

						if (mReceiveByteCnt >= 1023) { // Prevent buffer overflow
								mReceiveByteCnt = 0;
						}

						char vRouteTarget = vData[i];

						//if (vData[i].operator != (0)) { // pomyśleć zmianę tego
						mReceiveBuffer[mReceiveByteCnt] = vData[i];
						++mReceiveByteCnt;
						//}

						RouteData(vRouteTarget);
				}
		}
}
int32_t CClient::ByteArrayToInt(QByteArray aData) {
		int32_t vResult;
		QDataStream vData(&aData, QIODevice::ReadWrite);
		vData >> vResult;
		return vResult;

}
void CClient::RouteData(char aData) {
		qDebug() << "bu";

		switch (mReceiveDataMode) {

				case Mode_Receive_File_Data : {
						int32_t vCurrentSize = *mSize;
						qDebug() << "zu";

						while ((vCurrentSize == 0 && mBuffer->size() >= 4) || (vCurrentSize > 0 &&
										mBuffer->size() >= vCurrentSize)) { //While can process data, process it
								if (vCurrentSize == 0 &&
												mBuffer->size() >=
												4) { //if size of data has received completely, then store it on our global variable
										vCurrentSize = ByteArrayToInt(mBuffer->left(4)); // było mid(0,4)
										*mSize = vCurrentSize;
										mBuffer->remove(0, 4);
								}

								if (vCurrentSize > 0 && mBuffer->size() >=
												vCurrentSize) { // If data has received completely, then emit our SIGNAL with the data
										QByteArray vData = mBuffer->left(vCurrentSize);  // było mid(0,vcurrentsize )
										mBuffer->remove(0, vCurrentSize);
										vCurrentSize = 0;
										*mSize = vCurrentSize;
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

						break;
				}

				case Mode_Receive_File_CheckSum: {
						if (aData == 0x0A) {
								ServeReceivedMessage(); //, mReceiveByteCnt
								mReceiveDataMode = Mode_Receive_File_Data;
								mReceiveByteCnt = 0;
						}

						break;
				}

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
		delete mBuffer;
		delete mSize;
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

