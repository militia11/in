#include <QString>
#include <QtTest>

class TestInitServerTest : public QObject
{
	Q_OBJECT

public:
	TestInitServerTest();

private Q_SLOTS:
	void testCas();
};

TestInitServerTest::TestInitServerTest()
{

}

void TestInitServerTest::testCas()
{
//	CServer *vServer = new CServer;
//	vServer->Run();
//	QVERIFY(vServer.isListening());
}

QTEST_APPLESS_MAIN(TestInitServerTest)

#include "tst_TestInitServerTest.moc"
