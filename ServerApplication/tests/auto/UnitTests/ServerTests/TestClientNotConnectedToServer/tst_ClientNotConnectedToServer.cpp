#include "assert.h"

#include <QString>
#include <QtTest>
/*
#include "src/libs/controllers/CServer.h"
#include "src/libs/controllers/CServerWrapper.h"
#include "src/libs/controllers/CSettings.h"
#include "src/libs/controllers/CReceiverMock.h"
#include "src/libs/controllers/CReceiverMockFactory.h"
*/
class ClientNotConnectedToServer : public QObject {
    Q_OBJECT

  public:
    ClientNotConnectedToServer();

		void SaveSettingsInConfigHelper(
				QString aValue,
				QString aKey,
				QString aGroup);

  private Q_SLOTS:
	/*  void TestGetReceiver();
    void TestVerifyPortNumber();
    void TestUpdatePortNumber();
		void TestEmptySocketTest();
		void Test();*/
};

ClientNotConnectedToServer::ClientNotConnectedToServer() {
}
/*
void ClientNotConnectedToServer::SaveSettingsInConfigHelper(QString aValue, QString aKey, QString aGroup)
{
	QSettings vQSettings;
	vQSettings.beginGroup(aGroup);
	vQSettings.setValue(aKey, aValue);
	vQSettings.endGroup();
}

void ClientNotConnectedToServer::TestGetReceiver() {
		CServerWrapper vServer(new CReceiverMockFactory);

    IReceiver *vReceiver {vServer.GetReceiver()};
    CReceiverMock *vReceiverMock {dynamic_cast<CReceiverMock *>(vReceiver)};
    QVERIFY(vReceiverMock);
}

void ClientNotConnectedToServer::TestVerifyPortNumber() {
    CServer vServer (new CReceiverMockFactory());

		uint16_t vPortNumber {1234};
    bool vIsListen {vServer.listen(QHostAddress::Any, vPortNumber)};
    QVERIFY(vIsListen);

    // Verify port number
    uint16_t vPortNumberFromServer {vServer.serverPort()};
    QCOMPARE(vPortNumber, vPortNumberFromServer);
}

void ClientNotConnectedToServer::TestUpdatePortNumber() {
		CServerWrapper vServer (new CReceiverMockFactory());

		CSettings vSettings;

		int vPortNumber {3811};
		SaveSettingsInConfigHelper(QString::number(vPortNumber), "port", "server");

		vServer.ForTestUpdatePortNumber();
		int vExpectedPortNumberFromSettings {vSettings.GetPortNumber()};
		QCOMPARE(vServer.ForTestGetPortNumber(),vExpectedPortNumberFromSettings);
}

void ClientNotConnectedToServer::TestEmptySocketTest() {
    CServer vServer (new CReceiverMockFactory());
    QTcpSocket *vSocket {vServer.GetReceiver()->GetSocket()};

		QEXPECT_FAIL("", "Wskaźnik na gniazdo powinien być NULL "
								 "nie było połączenia klienta.", Continue);
		QVERIFY(vSocket);
}

void ClientNotConnectedToServer::Test() {
  CServer vServer (new CReceiverMockFactory());
	int16_t vPortNumber {1234};

  bool vIsListen {vServer.listen(QHostAddress::Any, vPortNumber)};
	QVERIFY(vIsListen);

  QVERIFY(vServer.isListening());
}
*/
QTEST_MAIN(ClientNotConnectedToServer)

#include "tst_ClientNotConnectedToServer.moc"
