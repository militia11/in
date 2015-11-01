#include "CServer.h"

#include "libs/controllers/CSettings.h"
#include "libs/controllers/CReceiver.h"

#include <QTcpSocket>
#include <QDebug>

CServer::CServer() :
    mReceiver(NULL) {
    UpdatePortNumber();

    connect(this, SIGNAL(newConnection()), this, SLOT(IncomingConnection()));
}

CServer::~CServer() {
    delete mReceiver;
		mReceiver = nullptr;
}

void CServer::Run() {
    if (!this->listen(QHostAddress::Any, mPortNumber)) {
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
    return mReceiver;
}

void CServer::IncomingConnection() {
    mReceiver = new CClient();
    emit CreateClient();

    QTcpSocket *vSocket = nextPendingConnection();
    mReceiver->Connect(vSocket);

    PauseAccepting();

    const char *vMessage = "Witaj kliencie\n";
    mReceiver->ResponeToClient(vMessage);
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
    connect(mReceiver, SIGNAL(Disconnect()), this, SLOT(ResumeAccepting()),
            Qt::DirectConnection);

    connect(mReceiver, SIGNAL(Connected()), this, SLOT(PauseAccepting()),
            Qt::DirectConnection);
}

void CServer::UpdatePortNumber() {
    CSettings vSettings;
    mPortNumber = vSettings.GetPortNumber();
}
