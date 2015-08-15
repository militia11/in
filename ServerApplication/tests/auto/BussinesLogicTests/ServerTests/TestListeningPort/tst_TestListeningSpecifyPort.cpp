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
	//	CServer *vServer = new CServer;
	//	bool vIsListen = vServer->listen(QHostAddress::Any, 1234);
	//	QVERIFY(vIsListen);
}

QTEST_APPLESS_MAIN(TestListeningSpecifyPort)

#include "tst_TestListeningSpecifyPort.moc"
