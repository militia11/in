#include "CServer.h"

#include <QDebug>
#include <QTcpSocket>

#include "src/libs/controllers/CSettings.h"
#include "src/libs/controllers/CReceiver.h"
#include "tests/auto/UnitTests/testlibs/CReceiverMock.h"

CServer::CServer(IReceiverFactory *aReceiversFactory) :
  mReceiversFactory(aReceiversFactory) {
  UpdatePortNumber();
  mReceiver = mReceiversFactory->Make();
  ConnectClientSignals();
  connect(this, SIGNAL(newConnection()), this, SLOT(IncomingConnection()));
}

CServer::~CServer() {
  delete mReceiver;
  mReceiver = nullptr;
}

void CServer::Run() {
  (ListenOnSpecifyPort()) ? MessageStatus("Serwer nasłuchuje...", 2400) :
  throw std::runtime_error("Nie można wystartować serwera");
}

void CServer::StopListening() {
  MessageStatus("Wyłączone nasłuchiwanie serwera", 2400);
  close();
}

IReceiver *CServer::GetReceiver() const {
  return mReceiver;
}

void CServer::IncomingConnection() {
  qDebug() << "incoming connection...";
  QTcpSocket *vSocket {nextPendingConnection()};
  TryConnect(vSocket);

  IReceiver *vIReceiver {mReceiver};
  CReceiver *vReceiver {dynamic_cast<CReceiver *>(vIReceiver)};

  if (vReceiver) {
	PauseAccepting();
  }

  mReceiver->ResponeToClient("Witaj kliencie\n");
  emit ConnectClient();
}

void CServer::ResumeAccepting() {
  emit ChangeServerStatus();
  QTcpServer::resumeAccepting();
}

void CServer::PauseAccepting() {
  emit ChangeServerStatus();
  QTcpServer::pauseAccepting();
}

void CServer::TryConnect(QTcpSocket *aSocket) {
  try {
	mReceiver->Connect(aSocket);
  } catch (std::runtime_error aError) {
	SocketError(aError.what());
  }
}

bool CServer::ListenOnSpecifyPort() {
  return this->listen(QHostAddress::Any, mPortNumber);
}

void CServer::SocketError(const char *aText) {
  qDebug() << "Socket Error: " + QString::fromStdString(aText);
}

void CServer::ConnectClientSignals() {
  connect(mReceiver, SIGNAL(Disconnect()), this, SLOT(ResumeAccepting()),
		  Qt::DirectConnection);

  connect(this, SIGNAL(ConnectClient()), this, SLOT(PauseAccepting()),
		  Qt::DirectConnection);

  connect(mReceiver, SIGNAL(ReceiveDataProgressChanged(int)), this,
		  SIGNAL(ReceiveDataProgressChanged(int)),
		  Qt::DirectConnection);
}

void CServer::UpdatePortNumber() {
  CSettings vSettings;
  mPortNumber = 1234;//vSettings.GetPortNumber();
}
