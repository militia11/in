#include "CServerWrapper.h"

CServerWrapper::CServerWrapper(IReceiverFactory *aReceiversFactory) :
    CServer(aReceiversFactory) {}

void CServerWrapper::ForTestIncomingConnection() {
    IncomingConnection();
}

void CServerWrapper::ForTestSetPortNumber(int aPortNumber) {
    mPortNumber = aPortNumber;
}

int CServerWrapper::ForTestGetPortNumber() {
    return mPortNumber;
}

void CServerWrapper::ForTestUpdatePortNumber() {
    UpdatePortNumber();
}


