#include <QString>
#include <QtTest>

#include "src/libs/controllers/CServer.h"
#include "src/libs/controllers/CReceiverFactoryImplementation.h"
#include "tests/auto/UnitTests/testlibs/CReceiverMock.h"
#include "tests/auto/UnitTests/testlibs/CReceiverMockFactory.h"
#include "tests/auto/UnitTests/testlibs/CServerWrapper.h"

class ListeningTests : public QObject {
  Q_OBJECT

 public:
  ListeningTests();

 private Q_SLOTS:
  void TestIncomingConnectionMethod();
  void TestAreListeningRunServerMethod();
  void TestAreListeningStopServerMethod();
  void TestAreListeningOnSpecifyPort();
  void TestAreListeningOnWrongPortNumber();
  void TestAreListeningWhenTurnOffListening();
  void TestConnectToServer();

  //qApp->processEvents(); dodać do init test
};

ListeningTests::ListeningTests() {
}

void ListeningTests::TestIncomingConnectionMethod() {
  CServerWrapper vServer(new CReceiverMockFactory);

  IReceiver *vReceiver {vServer.GetReceiver()};
  CReceiverMock *vReceiverMock {dynamic_cast<CReceiverMock *>(vReceiver)};
  QVERIFY(vReceiverMock);

  vServer.ForTestIncomingConnection();

  QString vActualLog {vReceiverMock->GetLog()};
  QString vExpectedLog("->Connect(0)->ResponeToClient(Witaj kliencie\n)");
  QCOMPARE(vActualLog, vExpectedLog);
}

void ListeningTests::TestAreListeningRunServerMethod() {
  CServer vServer(new CReceiverMockFactory);
  vServer.Run();

  QVERIFY(vServer.isListening());
}

void ListeningTests::TestAreListeningStopServerMethod() {
  CServer vServer(new CReceiverMockFactory());
  vServer.Run();
  QVERIFY(vServer.isListening());

  // Stop listening
  vServer.StopListening();

  QEXPECT_FAIL("", "Serwer nie powinien nasłuchiwać", Continue);
  QVERIFY(vServer.isListening());
}

void ListeningTests::TestAreListeningOnSpecifyPort() {
  CServer vServer(new CReceiverMockFactory());


  int vPortNumber {vServer.serverPort()};
  qDebug() << "x" << vPortNumber;
  //  Check turn on listening without function Run
  bool vIsListen {vServer.listen(QHostAddress::Any, vPortNumber)};
  QVERIFY(vIsListen);
}

void ListeningTests::TestAreListeningOnWrongPortNumber() {
  CServer vServer(new CReceiverMockFactory());
  vServer.Run();

  quint16 vPortNumber {21}; // Wrong number
  bool vIsListen {vServer.listen(QHostAddress::Any, vPortNumber)};

  QEXPECT_FAIL("", "Serwer nie powinien wystartować na podanym numerze portu"
			   "Nie jest to właściwy numer portu.", Continue);
  QVERIFY(vIsListen);
}

void ListeningTests::TestAreListeningWhenTurnOffListening() {
  CServer vServer (new CReceiverMockFactory());

  QEXPECT_FAIL("", "Nasłuchiwanie serwera jeszcze nie uruchomione. "
			   "Serwer nie powinien nasłuchiwać", Continue);
  QVERIFY(vServer.isListening());
}

void ListeningTests::TestConnectToServer() {
  CServer vServer(new CReceiverMockFactory());
  vServer.Run();
  QVERIFY(vServer.isListening());

  QTcpSocket vSocket ;
  int vPortNumber {vServer.serverPort()};
  vSocket.connectToHost(QHostAddress("127.0.0.1"), vPortNumber);

  bool vConnectionEstablished {vSocket.waitForConnected()};
  QVERIFY(vConnectionEstablished);
  QVERIFY( vSocket.state() == QTcpSocket::ConnectedState );
}

QTEST_MAIN(ListeningTests)

#include "ListeningTests.moc"
