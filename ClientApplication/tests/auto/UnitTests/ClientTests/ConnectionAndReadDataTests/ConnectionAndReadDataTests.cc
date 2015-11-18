#include <QString>
#include <QtTest>

#include "src/libs/controllers/CClient.h"
#include "tests/auto/UnitTests/testlib/CQTcpSocketMock.h"
#include <QAbstractSocket>
class ConnectionAndReadDataTests : public QObject
{
    Q_OBJECT

  public:
    ConnectionAndReadDataTests();

  private Q_SLOTS:
    void TestConnectionConnectedState();
    void TestConnectionUnConnectedState();
    void TestConnectionClosingState();
		void TestConnectionHostLookupState();
		void TestConnectionListeninigState();
		void TestConnectionBoundState();
		void TestConnectionConnectingState();

};

ConnectionAndReadDataTests::ConnectionAndReadDataTests()
{
}

void ConnectionAndReadDataTests::TestConnectionConnectedState()
{
  CQTcpSocketMock *vSocket = new CQTcpSocketMock;
  vSocket->ForTestSetSocketState(QAbstractSocket::ConnectedState);

  CClient vClient(vSocket);
  vClient.ConnectToHost("127.0.0.1");

  QString vExpectedLog = "->connectToHost(127.0.0.1, 1234)";
  QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

void ConnectionAndReadDataTests::TestConnectionUnConnectedState()
{
  CQTcpSocketMock *vSocket = new CQTcpSocketMock;
  vSocket->ForTestSetSocketState(QAbstractSocket::ClosingState);

  CClient vClient(vSocket);

  bool vPass = false;
  try {
     vClient.ConnectToHost("127.0.0.1");
  } catch (QAbstractSocket::SocketError vError) {
		if(vError == QAbstractSocket::SocketTimeoutError) {
      vPass = true;
    }
  }
  QVERIFY(vPass);
  QString vExpectedLog = "->connectToHost(127.0.0.1, 1234)";
  QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

void ConnectionAndReadDataTests::TestConnectionClosingState()
{
	CQTcpSocketMock *vSocket = new CQTcpSocketMock;
	vSocket->ForTestSetSocketState(QAbstractSocket::UnconnectedState);

	CClient vClient(vSocket);

	bool vPass = false;
	try {
		 vClient.ConnectToHost("127.0.0.1");
	} catch (QAbstractSocket::SocketError vError) {
		if(vError == QAbstractSocket::UnknownSocketError) {
			vPass = true;
		}
	}
	QVERIFY(vPass);
	QString vExpectedLog = "->connectToHost(127.0.0.1, 1234)";
	QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

void ConnectionAndReadDataTests::TestConnectionHostLookupState()
{
	CQTcpSocketMock *vSocket = new CQTcpSocketMock;
	vSocket->ForTestSetSocketState(QAbstractSocket::HostLookupState);

	CClient vClient(vSocket);

	bool vPass = false;
	try {
		 vClient.ConnectToHost("127.0.0.1");
	} catch (QAbstractSocket::SocketError vError) {
		if(vError == QAbstractSocket::HostNotFoundError) {
			vPass = true;
		}
	}
	QVERIFY(vPass);
	QString vExpectedLog = "->connectToHost(127.0.0.1, 1234)";
	QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

void ConnectionAndReadDataTests::TestConnectionListeninigState()
{
	CQTcpSocketMock *vSocket = new CQTcpSocketMock;
	vSocket->ForTestSetSocketState(QAbstractSocket::ListeningState);

	CClient vClient(vSocket);

	bool vPass = false;
	try {
		 vClient.ConnectToHost("127.0.0.1");
	} catch (QAbstractSocket::SocketError vError) {
		if(vError == QAbstractSocket::SocketTimeoutError) {
			vPass = true;
		}
	}
	QVERIFY(vPass);
	QString vExpectedLog = "->connectToHost(127.0.0.1, 1234)";
	QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

void ConnectionAndReadDataTests::TestConnectionBoundState()
{
	CQTcpSocketMock *vSocket = new CQTcpSocketMock;
	vSocket->ForTestSetSocketState(QAbstractSocket::BoundState);

	CClient vClient(vSocket);

	bool vPass = false;
	try {
		 vClient.ConnectToHost("127.0.0.1");
	} catch (QAbstractSocket::SocketError vError) {
		if(vError == QAbstractSocket::SocketTimeoutError) {
			vPass = true;
		}
	}

	QVERIFY(vPass);
	QString vExpectedLog = "->connectToHost(127.0.0.1, 1234)";
	QCOMPARE(vSocket->GetLog(), vExpectedLog);
}
void ConnectionAndReadDataTests::TestConnectionConnectingState() {
	CQTcpSocketMock *vSocket = new CQTcpSocketMock;
	vSocket->ForTestSetSocketState(QAbstractSocket::ConnectingState);

	CClient vClient(vSocket);

	bool vPass = false;

	try {
		 vClient.ConnectToHost("127.0.0.1");
	} catch (QAbstractSocket::SocketError vError) {
		if(vError == QAbstractSocket::UnknownSocketError) {
			vPass = true;
		}
	}

	QVERIFY(vPass);
	QString vExpectedLog = "->connectToHost(127.0.0.1, 1234)";
	QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

QTEST_APPLESS_MAIN(ConnectionAndReadDataTests)

#include "ConnectionAndReadDataTests.moc"
