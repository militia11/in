#include "CQTcpSocketMock.h"
#include <QHostAddress>

CQTcpSocketMock::CQTcpSocketMock(QObject *parent) :
  QTcpSocket(parent)
{
}

const QString CQTcpSocketMock::GetLog() const
{
  return mLog;
}

bool CQTcpSocketMock::waitForBytesWritten(int msecs)
{
   mLog += "->waitForBytesWritten(" + QString::number(msecs) + ")";
   return true;
}

void CQTcpSocketMock::connectToHost(const QString &hostName, quint16 port, OpenMode mode, NetworkLayerProtocol protocol) {
   mLog += "->connectToHost(" + hostName + ", " + QString::number(port) + ")";
}

void CQTcpSocketMock::ForTestSetSocketState(QAbstractSocket::SocketState aState)
{
  this->setSocketState(aState);
}
