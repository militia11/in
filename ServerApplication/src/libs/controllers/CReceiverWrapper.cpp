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

//void CReceiverWrapper::TestSetMessageFileChecksum(char *aMess) {
//  mMessageFileChecksum =
//}
