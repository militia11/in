#include <QString>
#include <QtTest>

#include "../ServerApplication/src/libs/controllers/CServer.h"
#include "../ServerApplication/src/libs/controllers/CServerWrapper.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMockFactory.h"

class ListeningTests : public QObject {
  Q_OBJECT

 public:
  ListeningTests();

 private Q_SLOTS:
  void TestIncomingConnection();
  void TestAreListeningRunServerMethod();
  void TestAreListeningStopServerMethod();
  void TestAreListeningOnSpecifyPort();
  void TestAreListeningOnWrongPortNumber();
  void Test();
  void Test2();
};

ListeningTests::ListeningTests() {
}

void ListeningTests::TestIncomingConnection() {
  CReceiverMockFactory *vMockFactory = new CReceiverMockFactory;
  CServerWrapper vServer(vMockFactory);

  IReceiver *vReceiver = vServer.GetReceiver();
  CReceiverMock *vReceiverMock = dynamic_cast<CReceiverMock *>(vReceiver);
  QVERIFY(vReceiverMock);

  vServer.TestIncomingConnection();

  QString vActualLog = vReceiverMock->GetLog();
  QString vExpectedLog("->Connect->ResponeToClient(Witaj kliencie\n)");
  QCOMPARE(vActualLog, vExpectedLog);
}

void ListeningTests::TestAreListeningRunServerMethod() {
  CServer *vServer = new CServer(new CReceiverMockFactory());
  vServer->Run();

  // If works fine status of listening is true
  QVERIFY(vServer->isListening());
}

void ListeningTests::TestAreListeningStopServerMethod() {
  // Start listening
  CServer *vServer = new CServer(new CReceiverMockFactory());
  vServer->Run();
  QVERIFY(vServer->isListening());

  // Verify if stop listening
  vServer->StopListening();

  QEXPECT_FAIL("", "Serwer nie powinien nasłuchiwać", Continue);
  QVERIFY(vServer->isListening());
}

void ListeningTests::TestAreListeningOnSpecifyPort() {
  // Verify status of listening
  CServer *vServer = new CServer(new CReceiverMockFactory());
  int16_t vPortNumber = 1234;
  vServer->Run();
  bool vIsListen = vServer->listen(QHostAddress::Any, vPortNumber);

  QVERIFY(vIsListen);

  // Verify port number
  int16_t vPortNumberFromServer =  vServer->serverPort();

  QCOMPARE(vPortNumberFromServer, vPortNumber);
}

void ListeningTests::TestAreListeningOnWrongPortNumber() {
  // Verify status of listening
  CServer *vServer = new CServer(new CReceiverMockFactory());
  quint16 vPortNum = 21; // wrong number

  bool vIsListen = vServer->listen(QHostAddress::Any, vPortNum);

  QEXPECT_FAIL("", "Serwer nie powinien wystartować na podanym numerze portu"
               "Za mała liczba", Continue);
  QVERIFY(vIsListen);
}

void ListeningTests::Test() {
  // Check status of listening
  CServer *vServer = new CServer(new CReceiverMockFactory());

  QEXPECT_FAIL("", "Nasłuchiwanie serwera jeszcze nie uruchomione. "
               "Serwer nie powinien nasłuchiwać", Continue);
  QVERIFY(vServer->isListening());
}

void ListeningTests::Test2()
{
  // Start listening
  /*
  CServer *vServer = new CServer(new CReceiverMockFactory());
  vServer->Run();
  QVERIFY(vServer->isListening());
QTcpSocket *vSocket;
  vSocket->connectToHost("127.0.0.1", 1234);
  bool vConnected = vSocket->waitForConnected(90000); ///@todo komentarz skad taka liczba*/
}

QTEST_APPLESS_MAIN(ListeningTests)

#include "ListeningTests.moc"
