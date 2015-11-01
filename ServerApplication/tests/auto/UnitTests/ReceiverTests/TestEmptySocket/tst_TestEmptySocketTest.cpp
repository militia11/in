#include <QString>
#include <QtTest>

//#include "libs/controllers/CServer.h"
//#include "libs/controllers/CReceiver.h"

class TestEmptySocketTest : public QObject {
    Q_OBJECT

  public:
    TestEmptySocketTest();

  private Q_SLOTS:
    void testCase();
};

TestEmptySocketTest::TestEmptySocketTest() {
}

void TestEmptySocketTest::testCase() {
	 /* CServer *vServer = new CServer();
    QTcpSocket *vSocket = vServer->GetClient()->GetSocket();

    QEXPECT_FAIL("", "Wskaźnik na gniazdo powinien być NULL "
                 "nie było połączenia klienta.", Continue);
		QVERIFY(vSocket);*/
}

QTEST_APPLESS_MAIN(TestEmptySocketTest)

#include "tst_TestEmptySocketTest.moc"
