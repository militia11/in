#include "CQTcpSocketMockInServer.h"

CQTcpSocketMockInServer::CQTcpSocketMockInServer() {
}

const QString CQTcpSocketMockInServer::GetLog() const {
  return mLog;
}

qint64 CQTcpSocketMockInServer::bytesAvailable() const {
  mLog += "->bytesAvailable()";
  return -1;
}
