#include <QString>
#include <QtTest>

//#include "libs/controllers/CServer.h"

class ServerStopListening : public QObject {
    Q_OBJECT

  public:
    ServerStopListening();

  private Q_SLOTS:
    void TestServerStopListening();
};

ServerStopListening::ServerStopListening() {
}

void ServerStopListening::TestServerStopListening() {
    // Start listening
		/*CServer *vServer = new CServer;
    vServer->Run();

    QVERIFY(vServer->isListening());

    // Verify if stop listening
    vServer->StopListening();

    QEXPECT_FAIL("", "Serwer nie powinien nasłuchiwać", Continue);
		QVERIFY(vServer->isListening());*/
}

QTEST_APPLESS_MAIN(ServerStopListening)

#include "tst_ServerStopListening.moc"
