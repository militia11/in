#include "CServerMock.h"

//#include "CServer.h"

#include "libs/controllers/CSettings.h"


#include <QTcpSocket>
#include <QDebug>

void CServerMock::Run() {
    /* if (!this->listen(QHostAddress::Any, mPortNum)) {
         MessageStatus("Nie można wystartować serwera", 2400);
     } else {
         MessageStatus("Serwer nasłuchuje... ", 2400);
     }
     */
}

void CServerMock::StopListening() {
    //MessageStatus("Wyłączone nasłuchiwanie serwera", 2400);

    //close();
}

CClient *CServerMock::GetClient() const {
    //mLog += "->GetClient()";

    return 0;//mClient;
}

void CServerMock::IncomingConnection() {
    //mLog += "->IncomingConnection()";

    /* mClient = new CClient();

     emit CreateClient();

     QTcpSocket *vSocket = nextPendingConnection();
     mClient->Connect(vSocket);

     PauseAccepting();

     const char *vMessage = "Witaj kliencie\n";
     mClient->ResponeToClient(vMessage); */
}

void CServerMock::ResumeAccepting() {
    //mLog += "->ResumeAccepting()";
    //emit ChangeServerStatus();

    //QTcpServer::resumeAccepting();
}

void CServerMock::PauseAccepting() {
    //emit ChangeServerStatus();
    //emit ChangeServerStatus();

    // QTcpServer::pauseAccepting();
}

void CServerMock::ConnectClientSignals() {
    /* connect(mClient, SIGNAL(Disconnect()), this, SLOT(ResumeAccepting()),
             Qt::DirectConnection);

     connect(mClient, SIGNAL(Connected()), this, SLOT(PauseAccepting()),
             Qt::DirectConnection);*/
}

void CServerMock::UpdatePortNum() {
    //CSettings vSettings;
    //mPortNum = vSettings.GetPortNumber();
}
