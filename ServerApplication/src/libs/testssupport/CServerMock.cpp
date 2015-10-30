#include "CServerMock.h"

#include <QTcpSocket>
#include <QDebug>

#include "libs/controllers/CSettings.h"

const QString CServerMock::GetLog() const {
		return mLog;
}

void CServerMock::Run() {
		mLog += "->Run";
}

void CServerMock::StopListening() {
		mLog += "->StopListening";
}

CReceiver *CServerMock::GetClient() const {
		mLog += "->GetClient()";
		return nullptr;
}

void CServerMock::IncomingConnection() {
		mLog += "->IncomingConnection()";
}

void CServerMock::ResumeAccepting() {
		mLog += "->ResumeAccepting()";
}

void CServerMock::PauseAccepting() {
		mLog += "->PauseAccepting";
}

void CServerMock::ConnectClientSignals() {
	mLog += "->ConnectClientSignals";
}

void CServerMock::UpdatePortNumber() {
	mLog += "->UpdatePortNum";
}
