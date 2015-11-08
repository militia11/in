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
		void TestGetSocket();
		void TestGetNullSocket();
};

ConnectionTests::ConnectionTests() {
}

void ConnectionTests::TestConnectMethod() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestConnect(new QTcpSocket);

		QVERIFY(vReceiver.ForTestGetSocket());
		QVERIFY(vReceiver.ForTestGetReveiveBuffer());
		QVERIFY(vReceiver.ForTestGetDataSize());
}

void ConnectionTests::TestConnectMethodNullSocket() {
		CReceiverWrapper vReceiver;

		QString vErrorLog;

		try {
				vReceiver.ForTestConnect(nullptr);
		} catch (std::runtime_error aException) {
				vErrorLog.append(aException.what());
		}

		QString vExpectedLog("Nie można połączyć");
		QCOMPARE(vErrorLog, vExpectedLog);

		QEXPECT_FAIL("", "Gniazdo powinno być pustym wskaźnikiem", Continue);
		QVERIFY(vReceiver.ForTestGetSocket());

		QEXPECT_FAIL("", "Bufor powinien być pustym wskaźnikiem", Continue);
		QVERIFY(vReceiver.ForTestGetReveiveBuffer());

		QEXPECT_FAIL("", "DataSize powinien być pustym wskaźnikiem", Continue);
		QVERIFY(vReceiver.ForTestGetDataSize());
}

void ConnectionTests::TestGetSocket() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetSocket(new QTcpSocket);
		QVERIFY(vReceiver.ForTestGetSocket());
}

void ConnectionTests::TestGetNullSocket() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetSocket(nullptr);

		QEXPECT_FAIL("", "mSocket powinien być pustym wskaźnikiem", Continue);
		QVERIFY(vReceiver.ForTestGetSocket());
}

QTEST_MAIN(ConnectionTests)

#include "ConnectionTests.moc"
