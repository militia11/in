#include "QTcpSocketMock.h"

CTcpSocketMock::CTcpSocketMock(QObject *parent) :
	QTcpSocket(parent)
{
}

void CTcpSocketMock::write(const char *data)
{
	mLog += "->write(" + QString::fromStdString(data) + ")";
}

const QString CTcpSocketMock::GetLog() const
{
	 return mLog;
}
