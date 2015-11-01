#include <QString>
#include <QtTest>

//#include "libs/controllers/CServer.h"

class TestInitServerTest : public QObject {
    Q_OBJECT

  public:
    TestInitServerTest();

  private Q_SLOTS:
    void testCas();
};

TestInitServerTest::TestInitServerTest() {
}

void TestInitServerTest::testCas() {
    // Verify function Run()
    // If works fine status of listening is true
	 // CServer *vServer = new CServer;
	 // vServer->Run();

	 // QVERIFY(vServer->isListening());

		//vServer->GetClient()->ResponeToClient("Text testowy");
}

QTEST_APPLESS_MAIN(TestInitServerTest)

#include "tst_TestInitServerTest.moc"
