
#include "CServer.h"
#include <QTcpSocket>
#include <QDebug>

CServer::CServer(QObject *aParent)
		: QTcpServer(aParent),
			mClient(NULL)
{
		connect(this, SIGNAL(newConnection()), this, SLOT(IncomingConnection()));
}

CServer::~CServer() {
		delete mClient;
}

void CServer::Run() {
		if(listen(QHostAddress::Any, 1234)) {
				MessageStatus("Nie można wystartować serwera", 2400);
		} else {
			MessageStatus("Serwer uruchomiony", 2400);
		}
}

CClient *CServer::GetClient() const {
	return mClient;
}

void CServer::IncomingConnection() {
		mClient = new CClient();
		emit CreateClient();

		QTcpSocket *vSocket = nextPendingConnection();
		mClient->Connect(vSocket);

		const char* vMessage = "Witaj kliencie\n";
		mClient->ResponeToClient(vMessage);
}
