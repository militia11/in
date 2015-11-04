#include "CServerWrapper.h"

CServerWrapper::CServerWrapper(IReceiverFactory *aReceiversFactory) :
  CServer(aReceiversFactory) {}

void CServerWrapper::TestIncomingConnection()
{
  IncomingConnection();
}

void CServerWrapper::ForTestSetPortNumber(int aPortNumber)
{
  mPortNumber = aPortNumber;
}

int CServerWrapper::TestGetPortNumber()
{
  return mPortNumber;
}

void CServerWrapper::TestUpdatePortNumber()
{
  pdatePortNumber();
}
