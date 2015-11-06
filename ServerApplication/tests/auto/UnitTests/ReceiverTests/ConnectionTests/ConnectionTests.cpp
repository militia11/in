#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "src/libs/controllers/CReceiverWrapper.h"

class ConnectionTests : public QObject {
		Q_OBJECT

	public:
		ConnectionTests();

	private Q_SLOTS:
		void TestConnectMethod();
		void TestConnectMethodNullSocket();
};

ConnectionTests::ConnectionTests() {
}

void ConnectionTests::TestConnectMethod() {
		CReceiverWrapper vReceiver;

		vReceiver.TestConnect(new QTcpSocket);

		QVERIFY(vReceiver.ForTestGetSocket());
		QVERIFY(vReceiver.ForTestGetReveiveBuffer());
		QVERIFY(vReceiver.ForTestGetDataSize());
}

void ConnectionTests::TestConnectMethodNullSocket() {
		CReceiverWrapper vReceiver;

		vReceiver.TestConnect(nullptr);

		QEXPECT_FAIL("", "Gniazdo powinno być pustym wskaźnikiem", Continue);
		QVERIFY(!vReceiver.ForTestGetSocket());

		QEXPECT_FAIL("", "Bufor powinien być pustym wskaźnikiem", Continue);
		QVERIFY(!vReceiver.ForTestGetReveiveBuffer());

		QEXPECT_FAIL("", "DataSize powinien być pustym wskaźnikiem", Continue);
		QVERIFY(!vReceiver.ForTestGetDataSize());
}

QTEST_MAIN(ConnectionTests)

#include "ConnectionTests.moc"
