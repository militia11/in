#include "assert.h"

#include <QString>
#include <QtTest>

#include "../ServerApplication/src/libs/controllers/CServer.h"
#include "../ServerApplication/src/libs/controllers/CServerWrapper.h"
#include "../ServerApplication/src/libs/controllers/CSettings.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMockFactory.h"

#include "../ServerApplication/src/libs/controllers/CReceiverFactoryImplementation.h"

class ClientNotConnectedToServer : public QObject {
    Q_OBJECT

  public:
    ClientNotConnectedToServer();

  private Q_SLOTS:
    void TestGetReceiver();
    void TestVerifyPortNumber();
    void TestUpdatePortNumber();
		void Test();

};

ClientNotConnectedToServer::ClientNotConnectedToServer() {
}

void ClientNotConnectedToServer::TestGetReceiver() {
    CReceiverMockFactory *vMockFactory = new CReceiverMockFactory;
    CServerWrapper vServer(vMockFactory);

    IReceiver *vReceiver = vServer.GetReceiver();
    CReceiverMock *vReceiverMock = dynamic_cast<CReceiverMock *>(vReceiver);
    QVERIFY(vReceiverMock);

    delete vMockFactory;
}

void ClientNotConnectedToServer::TestVerifyPortNumber() {
    // Verify status of listening
    CServer *vServer = new CServer(new CReceiverMockFactory());
    // jakby nie działało później dać CReceiverFactoryImplementation()
    int16_t vPortNumber = 1234;

    bool vIsListen = vServer->listen(QHostAddress::Any, vPortNumber);
    QVERIFY(vIsListen);

    // Verify port number
    int16_t vPortNumberFromServer =  vServer->serverPort();
    QCOMPARE(vPortNumber, vPortNumberFromServer);
		delete vServer;
}

void ClientNotConnectedToServer::TestUpdatePortNumber() {
		/*CServerWrapper *vServer = new CServerWrapper(new CReceiverMockFactory());
		vServer->ForTestSetPortNumber(12);

    CSettings vSettings;
    int vPortNumberFromSettings = vSettings.GetPortNumber();

    //Save new port number
    QSettings vQSetting;
    vQSetting.beginGroup("server");
		int vPortNumber = 128;
    vQSetting.setValue("port", QString::number(vPortNumber));
    vQSetting.endGroup();
		qDebug()<< vServer->TestGetPortNumber();
		vServer->TestUpdatePortNumber();
		QCOMPARE(vServer->TestGetPortNumber(), vPortNumberFromSettings);*/
}

void ClientNotConnectedToServer::Test()
{
	// Verify status of listening
	CServer *vServer = new CServer(new CReceiverMockFactory());
	// jakby nie działało później dać CReceiverFactoryImplementation()
	int16_t vPortNumber = 1234;

	bool vIsListen = vServer->listen(QHostAddress::Any, vPortNumber);
	QVERIFY(vIsListen);

	// If works fine status of listening is true
	QVERIFY(vServer->isListening());
	delete vServer;
}

QTEST_APPLESS_MAIN(ClientNotConnectedToServer)

#include "tst_ClientNotConnectedToServer.moc"
