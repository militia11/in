#include <QString>
#include <QtTest>

#include "libs/controllers/CServer.h"

class TestListeningPortWrongNumberTest : public QObject
{
	Q_OBJECT

public:
	TestListeningPortWrongNumberTest();

private Q_SLOTS:
	void testCase();
};

TestListeningPortWrongNumberTest::TestListeningPortWrongNumberTest()
{
}

void TestListeningPortWrongNumberTest::testCase()
{
	// Verify status of listening
	CServer *vServer = new CServer;
	quint16 vPortNum = 1234;
	bool vIsListen = vServer->listen(QHostAddress::Any, vPortNum);
	QVERIFY(vIsListen);

	// Verify port number
	quint16 vPortNumFromServer =  vServer->serverPort();

	quint16 vWrongPortNum = 2221;
	QEXPECT_FAIL("", "Serwer wystartował na innym porcie", Continue);
	QCOMPARE(vWrongPortNum, vPortNumFromServer);
}

QTEST_APPLESS_MAIN(TestListeningPortWrongNumberTest)

#include "tst_TestListeningPortWrongNumberTest.moc"
