#include "CServer.h"

//#include <stdexcept>
#include <QDebug>
#include <QTcpSocket>

#include "src/libs/controllers/CSettings.h"
#include "src/libs/controllers/CReceiver.h"
#include "src/libs/controllers/CReceiverMock.h"

CServer::CServer(IReceiverFactory *aReceiversFactory) :
  mReceiversFactory(aReceiversFactory) {
  UpdatePortNumber();
  mReceiver = mReceiversFactory->Make();
  connect(this, SIGNAL(newConnection()), this, SLOT(IncomingConnection()));
  CSettings vSettings;
  qDebug()<<vSettings.GetPortNumber();
}

CServer::~CServer() {
  delete mReceiver;
  mReceiver = nullptr;
}

void CServer::Run() {

  if (!this->listen(QHostAddress::Any, mPortNumber)) {
qDebug() << "nie nasluch";
    ///@todo to inaczej zrobic w catch
    MessageStatus("Nie można wystartować serwera", 2400);
    //throw std::runtime_error("Nie można wystartować serwera");
  } else {
    MessageStatus("Serwer nasłuchuje...", 2400);
  }
}

void CServer::StopListening() {
  MessageStatus("Wyłączone nasłuchiwanie serwera", 2400);

  close();
}

IReceiver *CServer::GetReceiver() const {
  return mReceiver;
}

void CServer::IncomingConnection() {
  emit ConnectClient();

  QTcpSocket *vSocket {nextPendingConnection()};

  try {
    mReceiver->Connect(vSocket);
  } catch (std::runtime_error aError) {
     SocketError(aError.what());
  }

  IReceiver *vIReceiver {mReceiver};
  CReceiver *vReceiver {dynamic_cast<CReceiver *>(vIReceiver)};

  if (vReceiver) {
    PauseAccepting();
  }

  const char *vMessage {"Witaj kliencie\n"};
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

void CServer::SocketError(const char *aText) {
  ///@todo w statusie wyswielt tez/tylko
  qDebug() << "Socket Error: " + QString::fromStdString(aText);
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
