#include "assert.h"

#include <QString>
#include <QtTest>

#include "libs/controllers/CServer.h"
#include "libs/controllers/CClient.h"

class TestNoClientConnectedToServer : public QObject
{
	Q_OBJECT

public:
	TestNoClientConnectedToServer();

private Q_SLOTS:
	void testCase();
};

TestNoClientConnectedToServer::TestNoClientConnectedToServer()
{
}

void TestNoClientConnectedToServer::testCase()
{
	CServer *vServer = new CServer;
	CClient *vClient = vServer->GetClient();
	QEXPECT_FAIL("", "Nie powinno być klienta "
				"nie było połączenia przychodzącego.", Continue);
	QVERIFY(vClient);
}

QTEST_APPLESS_MAIN(TestNoClientConnectedToServer)

#include "tst_TestNoClientConnectedToServer.moc"
