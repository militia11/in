#include <QString>
#include <QtTest>

//#include "libs/controllers/CServer.h"

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
	 /* CServer *vServer = new CServer;
    int16_t vPortNumber = 1234;

    bool vIsListen = vServer->listen(QHostAddress::Any, vPortNumber);

    QVERIFY(vIsListen);

    // Verify port number
    int16_t vPortNumberFromServer =  vServer->serverPort();

		QCOMPARE(vPortNumber, vPortNumberFromServer);*/
}

QTEST_APPLESS_MAIN(TestListeningSpecifyPort)

#include "tst_TestListeningSpecifyPort.moc"
