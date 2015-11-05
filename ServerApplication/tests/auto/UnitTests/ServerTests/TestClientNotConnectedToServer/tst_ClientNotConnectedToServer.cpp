#include "assert.h"

#include <QString>
#include <QtTest>

#include "../ServerApplication/src/libs/controllers/CServer.h"
#include "../ServerApplication/src/libs/controllers/CServerWrapper.h"
#include "../ServerApplication/src/libs/controllers/CSettings.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMockFactory.h"

class ClientNotConnectedToServer : public QObject {
    Q_OBJECT

  public:
    ClientNotConnectedToServer();

  private Q_SLOTS:
    void TestGetReceiver();
    void TestVerifyPortNumber();
    void TestUpdatePortNumber();
		void TestEmptySocketTest();
		void Test();
};

ClientNotConnectedToServer::ClientNotConnectedToServer() {
}

void ClientNotConnectedToServer::TestGetReceiver() {
		CServerWrapper vServer(new CReceiverMockFactory);

    IReceiver *vReceiver = vServer.GetReceiver();
    CReceiverMock *vReceiverMock = dynamic_cast<CReceiverMock *>(vReceiver);
    QVERIFY(vReceiverMock);
}

void ClientNotConnectedToServer::TestVerifyPortNumber() {
		CServer *vServer {new CServer(new CReceiverMockFactory())};

		uint16_t vPortNumber {1234};
		bool vIsListen {vServer->listen(QHostAddress::Any, vPortNumber)};
    QVERIFY(vIsListen);

    // Verify port number
		uint16_t vPortNumberFromServer {vServer->serverPort()};
    QCOMPARE(vPortNumber, vPortNumberFromServer);

		delete vServer;
}

void ClientNotConnectedToServer::TestUpdatePortNumber() {
		CServerWrapper *vServer {new CServerWrapper(new CReceiverMockFactory())};
		vServer->ForTestSetPortNumber(12);

    CSettings vSettings;
    int vPortNumberFromSettings = vSettings.GetPortNumber();

    //Save new port number
    QSettings vQSetting;
    vQSetting.beginGroup("server");
		int vPortNumber = 128;
    vQSetting.setValue("port", QString::number(vPortNumber));
    vQSetting.endGroup();
		vServer->TestUpdatePortNumber();
		QCOMPARE(vServer->TestGetPortNumber(), vPortNumberFromSettings);
}

void ClientNotConnectedToServer::TestEmptySocketTest() {
		CServer *vServer {new CServer(new CReceiverMockFactory())};
		QTcpSocket *vSocket = vServer->GetReceiver()->GetSocket();

		QEXPECT_FAIL("", "Wskaźnik na gniazdo powinien być NULL "
								 "nie było połączenia klienta.", Continue);
		QVERIFY(vSocket);
}

void ClientNotConnectedToServer::Test() {
	CServer *vServer {new CServer(new CReceiverMockFactory())};
	int16_t vPortNumber {1234};

	bool vIsListen {vServer->listen(QHostAddress::Any, vPortNumber)};
	QVERIFY(vIsListen);
	QVERIFY(vServer->isListening());

	delete vServer;
}

QTEST_APPLESS_MAIN(ClientNotConnectedToServer)

#include "tst_ClientNotConnectedToServer.moc"
