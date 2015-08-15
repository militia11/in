
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
		if (!this->listen(QHostAddress::Any, 1222)) {
				MessageStatus("Nie można wystartować serwera", 2400);
		} else {
				MessageStatus("Serwer nasłuchuje ...", 2400);
		}
}

void CServer::StopListening() {
		MessageStatus("Wyłączone nasłuchiwanie serwera", 2400);

		close();
}

CClient *CServer::GetClient() const {
		return mClient;
}

void CServer::IncomingConnection() {
		mClient = new CClient();

		emit CreateClient();

		QTcpSocket *vSocket = nextPendingConnection();
		mClient->Connect(vSocket);

		PauseAccepting();

		const char *vMessage = "Witaj kliencie\n";
		mClient->ResponeToClient(vMessage);
}

void CServer::ResumeAccepting() {
		emit ChangeServerStatus();
		QTcpServer::resumeAccepting();		
}

void CServer::PauseAccepting() {
		emit ChangeServerStatus();
		QTcpServer::pauseAccepting();
}

void CServer::ConnectClientSignals() {
		connect(mClient, SIGNAL(Disconnect()), this, SLOT(ResumeAccepting()),
						Qt::DirectConnection);

		connect(mClient, SIGNAL(Connected()), this, SLOT(PauseAccepting()),
						Qt::DirectConnection);
}
