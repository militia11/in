#include "CServer.h"

CServer::CServer(QObject *parent) :
    QTcpServer(parent) {
}


void CServer::Run() {
    if (!this->listen(QHostAddress::Any, 1234)) {
      qDebug() << "Nie można wystartować serwera";
    } else {
      qDebug() << "Nasłuchuje...";
    }
}

void CServer::IncomingConnection(int aSocketDescriptor) {
    qDebug() << aSocketDescriptor << " Połączono...";
    //WatekSerwera *watek = new WatekSerwera(deskryptorGniazda, this);
    //connect(watek, SIGNAL(finished()), watek, SLOT(deleteLater()));
    //watek->start();
}
