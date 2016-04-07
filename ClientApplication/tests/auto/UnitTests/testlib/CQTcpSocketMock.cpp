#include "CQTcpSocketMock.h"
#include <QHostAddress>

CQTcpSocketMock::CQTcpSocketMock(QObject *parent) :
  QTcpSocket(parent) {
}

const QString CQTcpSocketMock::GetLog() const {
  return mLog;
}

qint64 CQTcpSocketMock::bytesAvailable() const {
  mLog += "->bytesAvailable()";
  return -1;
}

bool CQTcpSocketMock::waitForBytesWritten(int msecs) {
  mLog += "->waitForBytesWritten(" + QString::number(msecs) + ")";
  return true;
}

void CQTcpSocketMock::connectToHost(
  const QString &hostName,
  quint16 port,
  OpenMode mode,
  NetworkLayerProtocol protocol) {
  Q_UNUSED(mode);
  Q_UNUSED(protocol);
  mLog += "->connectToHost(" + hostName + ", " + QString::number(port) + ")";
}

void CQTcpSocketMock::ForTestSetSocketState(QAbstractSocket::SocketState
	aState) {
  setSocketState(aState);
}
