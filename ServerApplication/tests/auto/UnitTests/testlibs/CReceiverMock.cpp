#include "CReceiverMock.h"

QTcpSocket *CReceiverMock::GetSocket() const {
		return 0;
}

const QString CReceiverMock::GetLog() const {
    return mLog;
}

void CReceiverMock::NewData() {
    mLog += "->NewData";
}

void CReceiverMock::RouteData(char aData) {
	Q_UNUSED(aData);
}

void CReceiverMock::ServeReceivedMessage() {

}

bool CReceiverMock::HasMessageCorrectFormat(char *aMessage) {
	Q_UNUSED(aMessage);
	return true;
}

void CReceiverMock::ServeReceivedFileData() {

}

uint16_t CReceiverMock::CalculateFileDataChecksum(QByteArray aData) {
		 Q_UNUSED(aData);return 0;
}

int32_t CReceiverMock::ByteArrayToInt(QByteArray aData) {
		Q_UNUSED(aData);return 0;
}

void CReceiverMock::Connect(QTcpSocket *aSocket) {
	if(aSocket==0) {
		mLog += "->Connect(0)";  // aSocket should be is nullptr set in constructor
	}
}

void CReceiverMock::ConnectSocketSignals() {

}

void CReceiverMock::Disconnected() {

}

int CReceiverMock::ConvertMessageArrayToInt() {
    return 0;
}

void CReceiverMock::ResponeToClient(const char* aMessage) {
		mLog += "->ResponeToClient(" + QString::fromStdString(aMessage) + ")";
}
