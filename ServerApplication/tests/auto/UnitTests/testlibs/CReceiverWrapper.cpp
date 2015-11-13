#include "CReceiverWrapper.h"

char *CReceiverWrapper::ForTestGetMessageFileChecksum() {
    return mMessageFileChecksum;
}

int CReceiverWrapper::ForTestGetMessageSize() {
    return mMessageSize;
}

void CReceiverWrapper::ForTestSetMessageSize(int aSize) {
		mMessageSize = aSize;
}

void CReceiverWrapper::ForTestSetReceiveByteCount(int aByteCount) {
		mReceiveByteCount = aByteCount;
}

void CReceiverWrapper::ForTestConnect(QTcpSocket *aSocket) {
		Connect(aSocket);
}

bool CReceiverWrapper::ForTestHasMessageCorrectFormat(char *aMessage) {
		return HasMessageCorrectFormat(aMessage);
}

void CReceiverWrapper::ForTestSetMessage(char *aMessageFileChecksum) {
		int vMessageSize {sizeof(aMessageFileChecksum) - 1};

		for (auto i = 0; i < vMessageSize; ++i) {
				mMessageFileChecksum[i] = aMessageFileChecksum[i];
		}
}

void CReceiverWrapper::ForTestSetSocket(QTcpSocket *aSocket) {
		mSocket = aSocket;
}

void CReceiverWrapper::ForTestSetReceiveBuffer(QByteArray *aBuffer) {
		mReceiveBuffer = aBuffer;
}

void CReceiverWrapper::ForTestSetDataSize(int32_t *aDataSize) {
		mDataSize = aDataSize;
}

void CReceiverWrapper::ForTestServeReceivedMessage() {
	ServeReceivedMessage();
}

void CReceiverWrapper::ForTestDisconnected()
{
	Disconnected();
}

ReceiveDataMode CReceiverWrapper::ForTestGetReceiveDataMode() {
		return mReceiveDataMode;
}

QTcpSocket *CReceiverWrapper::ForTestGetSocket() {
		return mSocket;
}

QByteArray *CReceiverWrapper::ForTestGetReveiveBuffer() {
		return mReceiveBuffer;
}

void CReceiverWrapper::ForTestNewData() {
		NewData();
}

void CReceiverWrapper::ForTestRouteData(char aData) {
		RouteData(aData);
}

int CReceiverWrapper::ForTestGetReceiveByteCount() {
		return mReceiveByteCount;
}

void CReceiverWrapper::ForTestSetReceiveDataMode(ReceiveDataMode aMode) {
		mReceiveDataMode = aMode;
}

int32_t *CReceiverWrapper::ForTestGetDataSize() {
		return mDataSize;
}

int CReceiverWrapper::ForTestConvertMessageArrayToInt() {
		return ConvertMessageArrayToInt();
}
