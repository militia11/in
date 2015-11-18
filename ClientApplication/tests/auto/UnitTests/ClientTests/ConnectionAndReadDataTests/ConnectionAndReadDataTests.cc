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
//QAbstractSocket::UnknownSocketError
//QAbstractSocket::SocketTimeoutError
void ConnectionAndReadDataTests::TestConnectionClosingState()
{

}

QTEST_APPLESS_MAIN(ConnectionAndReadDataTests)

#include "ConnectionAndReadDataTests.moc"
