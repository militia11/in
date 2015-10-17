#include "CClientWrapper.h"

CClientWrapper::CClientWrapper() {
}

char *CClientWrapper::TestGetMessageFileChecksum() {
		return mMessageFileChecksum;
}

int CClientWrapper::TestGetMessageSize() {
	return mMessageSize;
}

void CClientWrapper::TestSetMessageSize(int aSize)
{
	mMessageSize = aSize;
}

//void CClientWrapper::TestSetMessageFileChecksum(char *aMess) {
	//  mMessageFileChecksum =
//}
