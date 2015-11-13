#include "assert.h"

#include <QString>
#include <QtTest>

#include "src/libs/controllers/CServer.h"
#include "src/libs/controllers/CSettings.h"
#include "tests/auto/UnitTests/testlibs/CReceiverMock.h"
#include "tests/auto/UnitTests/testlibs/CReceiverMockFactory.h"
#include "tests/auto/UnitTests/testlibs/CServerWrapper.h"

class ServerMethodsTests : public QObject {
    Q_OBJECT

  public:
		ServerMethodsTests();

		void SaveSettingsInConfigHelper(
				QString aValue,
				QString aKey,
				QString aGroup);

  private Q_SLOTS:
		void TestGetReceiver();
    void TestVerifyPortNumber();
    void TestUpdatePortNumber();
		void TestEmptySocketTest();
		void Test();
};

ServerMethodsTests::ServerMethodsTests() {
}

void ServerMethodsTests::SaveSettingsInConfigHelper(QString aValue, QString aKey, QString aGroup)
{
	QSettings vQSettings;
	vQSettings.beginGroup(aGroup);
	vQSettings.setValue(aKey, aValue);
	vQSettings.endGroup();
}

void ServerMethodsTests::TestGetReceiver() {
		CServerWrapper vServer(new CReceiverMockFactory);

    IReceiver *vReceiver {vServer.GetReceiver()};
    CReceiverMock *vReceiverMock {dynamic_cast<CReceiverMock *>(vReceiver)};
    QVERIFY(vReceiverMock);
}

void ServerMethodsTests::TestVerifyPortNumber() {
    CServer vServer (new CReceiverMockFactory());

		uint16_t vPortNumber {1234};
    bool vIsListen {vServer.listen(QHostAddress::Any, vPortNumber)};
    QVERIFY(vIsListen);

    // Verify port number
    uint16_t vPortNumberFromServer {vServer.serverPort()};
    QCOMPARE(vPortNumber, vPortNumberFromServer);
}

void ServerMethodsTests::TestUpdatePortNumber() {
		CServerWrapper vServer (new CReceiverMockFactory());
		CSettings vSettings;

		int vPortNumber {3811};
		SaveSettingsInConfigHelper(QString::number(vPortNumber), "port", "server");

		vServer.ForTestUpdatePortNumber();
		int vExpectedPortNumberFromSettings {vSettings.GetPortNumber()};
		QCOMPARE(vServer.ForTestGetPortNumber(),vExpectedPortNumberFromSettings);
}

void ServerMethodsTests::TestEmptySocketTest() {
    CServer vServer (new CReceiverMockFactory());
    QTcpSocket *vSocket {vServer.GetReceiver()->GetSocket()};

		QEXPECT_FAIL("", "Wskaźnik na gniazdo powinien być NULL "
								 "nie było połączenia klienta.", Continue);
		QVERIFY(vSocket);
}

void ServerMethodsTests::Test() {
  CServer vServer (new CReceiverMockFactory());
	int16_t vPortNumber {1234};

  bool vIsListen {vServer.listen(QHostAddress::Any, vPortNumber)};
	QVERIFY(vIsListen);
  QVERIFY(vServer.isListening());
}

QTEST_MAIN(ServerMethodsTests)

#include "ServerMethodsTests.moc"
