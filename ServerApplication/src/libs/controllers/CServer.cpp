#include "CServer.h"

#include "libs/controllers/CSettings.h"
#include "libs/controllers/CReceiver.h"

#include <QTcpSocket>
#include <QDebug>

CServer::CServer() :
    mClient(NULL) {
    UpdatePortNum();

    connect(this, SIGNAL(newConnection()), this, SLOT(IncomingConnection()));
}

CServer::~CServer() {
    delete mClient;
		mClient = nullptr;
}

void CServer::Run() {
    if (!this->listen(QHostAddress::Any, mPortNum)) {
        MessageStatus("Nie można wystartować serwera", 2400);
    } else {
        MessageStatus("Serwer nasłuchuje... ", 2400);
    }
}

void CServer::StopListening() {
    MessageStatus("Wyłączone nasłuchiwanie serwera", 2400);

    close();
}

IReceiver *CServer::GetClient() const {
    return mClient;
}

void CServer::IncomingConnection() {
    mClient = new CReceiver();
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

void CServer::UpdatePortNum() {
    CSettings vSettings;
    mPortNum = vSettings.GetPortNumber();
}
