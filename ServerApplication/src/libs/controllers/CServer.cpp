
#include "CServer.h"
#include <QTcpSocket>
#include <QDebug>

CServer::CServer(QObject *aParent)
		: QTcpServer(aParent),
			mClient(NULL) {
		connect(this, SIGNAL(newConnection()), this, SLOT(IncomingConnection()));
}

CServer::~CServer() {
		delete mClient;
}

void CServer::Run() {
		if (!listen(QHostAddress::Any, 1234)) {
				qDebug() << "Nie można wystartować serwera";
		} else {
				qDebug() << "Serwer nasłuchuje ...";
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

		char vMessage[] = "Witaj kliencie\n";
		mClient->ResponeToClient(vMessage);
}
