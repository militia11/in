#include "CReceiverMock.h"

QTcpSocket *CReceiverMock::GetSocket() const {
		return 0;
}

const QString CReceiverMock::GetLog() const {
	return mLog;
}

void CReceiverMock::NewData() {

}

void CReceiverMock::RouteData(char aData) {

}

bool CReceiverMock::HasMessageCorrectFormat(char *aMessage) {

}

void CReceiverMock::ServeReceivedFileData() {

}

uint16_t CReceiverMock::CalculateFileDataChecksum(QByteArray aData) {

}

int32_t CReceiverMock::ByteArrayToInt(QByteArray aData) {

}

void CReceiverMock::ConnectSocketSignals() {

}

void CReceiverMock::Disconnected() {

}

int CReceiverMock::ConvertMessageArrayToInt() {

}

void CReceiverMock::ResponeToClient(QByteArray aData) {

}
