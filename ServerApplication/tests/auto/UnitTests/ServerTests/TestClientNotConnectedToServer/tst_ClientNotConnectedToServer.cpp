#include "assert.h"

#include <QString>
#include <QtTest>

#include "libs/controllers/CServer.h"
#include "libs/controllers/CReceiver.h"

class ClientNotConnectedToServer : public QObject {
    Q_OBJECT

  public:
    ClientNotConnectedToServer();

  private Q_SLOTS:
    void TestClientNotConnectedToServer();
};

ClientNotConnectedToServer::ClientNotConnectedToServer() {
}

void ClientNotConnectedToServer::TestClientNotConnectedToServer() {
    CServer *vServer = new CServer;
		CReceiver *vClient = dynamic_cast<CReceiver *>(vServer->GetClient());

    QEXPECT_FAIL("", "Klient nie powinien zostać utworzony, "
                 "nie było połączenia przychodzącego.", Continue);
    QVERIFY(vClient);
}

QTEST_APPLESS_MAIN(ClientNotConnectedToServer)

#include "tst_ClientNotConnectedToServer.moc"
