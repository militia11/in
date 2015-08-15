#include <QString>
#include <QtTest>

class TestListeningSpecifyPort : public QObject
{
	Q_OBJECT

public:
	TestListeningSpecifyPort();

private Q_SLOTS:
	void testCase();
};

TestListeningSpecifyPort::TestListeningSpecifyPort()
{
}

void TestListeningSpecifyPort::testCase()
{
	//  Verify status of listening
	//	CServer *vServer = new CServer;
	//  quit16 vPortNum = 1234;
	//	bool vIsListen = vServer->listen(QHostAddress::Any, vPortNum4);
	//	QVERIFY(vIsListen);

	//  Verify port number
	//  quit16 vPortNumFromServer =  vServer->serverPort();
	//  QCOMPARE(vPortNum, vPortNumFromServer);
}

QTEST_APPLESS_MAIN(TestListeningSpecifyPort)

#include "tst_TestListeningSpecifyPort.moc"
