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

void CReceiverWrapper::ForTestConnect(QTcpSocket *aSocket)
{
	Connect(aSocket);
}

bool CReceiverWrapper::ForTestHasMessageCorrectFormat(char *aMessage)
{
	return HasMessageCorrectFormat(aMessage);
}

void CReceiverWrapper::ForTestSetMessage(char *aMessageFileChecksum)
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

int CReceiverWrapper::ForTestConvertMessageArrayToInt()
{
	return ConvertMessageArrayToInt();
}

//void CReceiverWrapper::TestSetMessageFileChecksum(char *aMess) {
//  mMessageFileChecksum =
//}
