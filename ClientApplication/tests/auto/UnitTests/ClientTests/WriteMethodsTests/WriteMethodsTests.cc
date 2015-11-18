#include <QString>
#include <QtTest>

#include "src/libs/controllers/CClient.h"
#include "tests/auto/UnitTests/testlib/CQTcpSocketMock.h"

class WriteMethodsTestsTest : public QObject
{
    Q_OBJECT

  public:
    WriteMethodsTestsTest();

  private Q_SLOTS:
    void TestWriteMessageMethodConnectedState();
    void TestWriteMessageMethodUnConnectedState();
    void TestWriteDataMethodConnectedState();
     void TestWriteDataMethodUnConnectedState();
};

WriteMethodsTestsTest::WriteMethodsTestsTest()
{
}

void WriteMethodsTestsTest::TestWriteMessageMethodConnectedState()
{
  CQTcpSocketMock *vSocket = new CQTcpSocketMock;
  vSocket->ForTestSetSocketState(QAbstractSocket::ConnectedState);

  CClient vClient(vSocket);
  vClient.WriteMessage(QByteArray());

  QString vExpectedLog = "->waitForBytesWritten(30000)";
  QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

void WriteMethodsTestsTest::TestWriteMessageMethodUnConnectedState()
{
  CQTcpSocketMock *vSocket = new CQTcpSocketMock;
  vSocket->ForTestSetSocketState(QAbstractSocket::UnconnectedState);

  CClient vClient(vSocket);
  vClient.WriteMessage(QByteArray());

  QString vExpectedLog = "";
  QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

void WriteMethodsTestsTest::TestWriteDataMethodConnectedState()
{
  CQTcpSocketMock *vSocket = new CQTcpSocketMock;
  vSocket->ForTestSetSocketState(QAbstractSocket::ConnectedState);

  CClient vClient(vSocket);
  vClient.WriteData(QByteArray());

  QString vExpectedLog = "->waitForBytesWritten(30000)";
  QCOMPARE(vSocket->GetLog(), vExpectedLog);

}

void WriteMethodsTestsTest::TestWriteDataMethodUnConnectedState()
{
  CQTcpSocketMock *vSocket = new CQTcpSocketMock;
  vSocket->ForTestSetSocketState(QAbstractSocket::UnconnectedState);

  CClient vClient(vSocket);
  vClient.WriteData(QByteArray());

  QString vExpectedLog = "";
  QCOMPARE(vSocket->GetLog(), vExpectedLog);
}

QTEST_APPLESS_MAIN(WriteMethodsTestsTest)

#include "WriteMethodsTests.moc"
