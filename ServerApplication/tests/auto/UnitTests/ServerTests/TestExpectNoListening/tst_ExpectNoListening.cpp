#include <QString>
#include <QtTest>

#include "libs/controllers/CServer.h"

class TestExpectListeningFail : public QObject {
    Q_OBJECT

  public:
    TestExpectListeningFail();

  private Q_SLOTS:
    void testCase();
};

TestExpectListeningFail::TestExpectListeningFail() {
}

void TestExpectListeningFail::testCase() {
    // Check status of listening
    CServer *vServer = new CServer;

    QEXPECT_FAIL("", "Serwer nie uruchomiony "
                 "nie powinien nasłuchiwać", Continue);
    QVERIFY(vServer->isListening());
}

QTEST_APPLESS_MAIN(TestExpectListeningFail)

#include "tst_TestExpectListeningFail.moc"
