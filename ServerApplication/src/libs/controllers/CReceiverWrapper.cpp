#include "CReceiverWrapper.h"

CReceiverWrapper::CReceiverWrapper() {
}

char *CReceiverWrapper::TestGetMessageFileChecksum() {
    return mMessageFileChecksum;
}

int CReceiverWrapper::TestGetMessageSize() {
    return mMessageSize;
}

void CReceiverWrapper::TestSetMessageSize(int aSize) {
	mMessageSize = aSize;
}

void CReceiverWrapper::TestConnect(QTcpSocket *aSocket)
{
	Connect(aSocket);
}

bool CReceiverWrapper::TestHasMessageCorrectFormat(char *aMessage)
{
	return HasMessageCorrectFormat(aMessage);
}

void CReceiverWrapper::TestSetMessage(char *aMessageFileChecksum)
{
	int vMessageSize {sizeof(aMessageFileChecksum) -1};

	for(auto i = 0; i < vMessageSize; ++i) {
		mMessageFileChecksum[i] = aMessageFileChecksum[i];
	}
}

QTcpSocket *CReceiverWrapper::ForTestGetSocket()
{
	return mSocket;
}

QByteArray *CReceiverWrapper::ForTestGetReveiveBuffer()
{
	return mReceiveBuffer;
}

int32_t *CReceiverWrapper::ForTestGetDataSize()
{
	return mDataSize;
}

int CReceiverWrapper::TestConvertMessageArrayToInt()
{
	return ConvertMessageArrayToInt();
}

//void CReceiverWrapper::TestSetMessageFileChecksum(char *aMess) {
//  mMessageFileChecksum =
//}
