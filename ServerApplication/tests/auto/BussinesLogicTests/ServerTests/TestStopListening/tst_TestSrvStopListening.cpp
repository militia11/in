#include <QString>
#include <QtTest>

#include "libs/controllers/CServer.h"

class TestSrvStopListening : public QObject {
    Q_OBJECT

  public:
    TestSrvStopListening();

  private Q_SLOTS:
    void testCase();
};

TestSrvStopListening::TestSrvStopListening() {
}

void TestSrvStopListening::testCase() {
    // Start listening
    CServer *vServer = new CServer;
    vServer->Run();
    QVERIFY(vServer->isListening());

    // Verify if listening stop
    vServer->StopListening();
    QEXPECT_FAIL("", "Serwer nie powinien nasłuchiwać", Continue);
    QVERIFY(vServer->isListening());
}

QTEST_APPLESS_MAIN(TestSrvStopListening)

#include "tst_TestSrvStopListening.moc"
