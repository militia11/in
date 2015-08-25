#include <QString>
#include <QtTest>

#include "libs/controllers/CServer.h"

class TestListeningSpecifyPort : public QObject {
    Q_OBJECT

  public:
    TestListeningSpecifyPort();

  private Q_SLOTS:
    void testCase();
};

TestListeningSpecifyPort::TestListeningSpecifyPort() {
}

void TestListeningSpecifyPort::testCase() {
    // Verify status of listening
    CServer *vServer = new CServer;
    quint16 vPortNum = 1234;
    bool vIsListen = vServer->listen(QHostAddress::Any, vPortNum);
    QVERIFY(vIsListen);

    // Verify port number
    quint16 vPortNumFromServer =  vServer->serverPort();
    QCOMPARE(vPortNum, vPortNumFromServer);
}

QTEST_APPLESS_MAIN(TestListeningSpecifyPort)

#include "tst_TestListeningSpecifyPort.moc"
