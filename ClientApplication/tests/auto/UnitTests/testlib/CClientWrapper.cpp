#include "CClientWrapper.h"

CClientWrapper::CClientWrapper(QTcpSocket *aSocket) : CClient(aSocket) {}

QByteArray CClientWrapper::ForTestIntToArray(int32_t aSource) {
  return IntToArray(aSource);
}

QByteArray CClientWrapper::ForTestPrepareMessageData(int16_t aChecksum) {
  return PrepareMessageData(aChecksum);
}

void CClientWrapper::ForTestReadData() {
  ReadData();
}
