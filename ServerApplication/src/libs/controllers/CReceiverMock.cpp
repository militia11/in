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

}

void CReceiverMock::ServeReceivedMessage() {

}

bool CReceiverMock::HasMessageCorrectFormat(char *aMessage) {

}

void CReceiverMock::ServeReceivedFileData() {

}

uint16_t CReceiverMock::CalculateFileDataChecksum(QByteArray aData) {
    return 0;
}

int32_t CReceiverMock::ByteArrayToInt(QByteArray aData) {
    return 0;
}

void CReceiverMock::Connect(QTcpSocket *aSocket) {
    mLog += "->Connect";
}

void CReceiverMock::ConnectSocketSignals() {

}

void CReceiverMock::Disconnected() {

}

int CReceiverMock::ConvertMessageArrayToInt() {
    return 0;
}

void CReceiverMock::ResponeToClient(QByteArray aData) {
    mLog += "->ResponeToClient(" + aData + ")";
}
