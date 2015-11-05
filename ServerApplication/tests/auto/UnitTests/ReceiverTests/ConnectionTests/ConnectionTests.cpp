#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "../ServerApplication/src/libs/controllers/CReceiverWrapper.h"

class ConnectionTests : public QObject {
		Q_OBJECT

	public:
		ConnectionTests();

	private Q_SLOTS:
		void TestConnection();
};

ConnectionTests::ConnectionTests() {
}

void ConnectionTests::TestConnection() {
		CReceiverWrapper vReceiver;

		vReceiver.TestConnect(new QTcpSocket);

		QVERIFY(vReceiver.ForTestGetSocket());
		QVERIFY(vReceiver.ForTestGetReveiveBuffer());
		QVERIFY(vReceiver.ForTestGetDataSize());

		//vReceiver->TestGetMessageFileChecksum();
}

QTEST_MAIN(ConnectionTests)

#include "ConnectionTests.moc"
