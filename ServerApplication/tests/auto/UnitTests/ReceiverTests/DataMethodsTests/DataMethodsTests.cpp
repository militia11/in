#include <QString>
#include <QtTest>

#include "src/libs/controllers/CReceiverWrapper.h"
#include <QHostAddress>
class DataMethodsTests : public QObject {
		Q_OBJECT

	public:
		DataMethodsTests();

	private Q_SLOTS:
		void TestNewDataMethod();
		void TestRouteDataMethod();
		void TestRouteDataPreventBufferOverflow();
		void TestRouteDataSpecifySign();
};

DataMethodsTests::DataMethodsTests() {
}

void DataMethodsTests::TestNewDataMethod() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetSocket(new QTcpSocket);
		vReceiver.ForTestNewData();
}

void DataMethodsTests::TestRouteDataMethod() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetReceiveDataMode(Mode_Receive_File_Checksum);
		QCOMPARE(vReceiver.ForTestGetReceiveByteCount(), 0);

		char vExpectedChar {'X'};
		vReceiver.ForTestRouteData(vExpectedChar);

		// Verify if in mMessageFileChecksum[mReceiveByteCount] is set char
		QCOMPARE(*vReceiver.ForTestGetMessageFileChecksum(), vExpectedChar);
		//mReceiveByteCount++;
		QCOMPARE(vReceiver.ForTestGetReceiveByteCount(), 1);
}

void DataMethodsTests::TestRouteDataPreventBufferOverflow() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetReceiveDataMode(Mode_Receive_File_Checksum);
		char vChar {'B'};
		// Safe value < 1024
		vReceiver.ForTestSetReceiveByteCount(1013);
		vReceiver.ForTestRouteData(vChar);
		// 1 more in RouteData function
		QCOMPARE(vReceiver.ForTestGetReceiveByteCount(), 1014);

		// Overflow value
		vReceiver.ForTestSetReceiveByteCount(1023);
		vReceiver.ForTestRouteData(vChar);
		QCOMPARE(vReceiver.ForTestGetReceiveByteCount(), 0);
}

void DataMethodsTests::TestRouteDataSpecifySign() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetReceiveDataMode(Mode_Receive_File_Checksum);
		char vChar {'<'};
		vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test Data"));
		vReceiver.ForTestSetReceiveByteCount(1);
		// Message size before call function RouteData
		QCOMPARE(vReceiver.ForTestGetMessageSize(), 0);

		vReceiver.ForTestRouteData(vChar);

		// Message size after call function RouteData
		QCOMPARE(vReceiver.ForTestGetMessageSize(), 2);

		// Receive byte count after call function RouteData
		QCOMPARE(vReceiver.ForTestGetReceiveByteCount(), 0);

		QCOMPARE(vReceiver.ForTestGetReceiveDataMode(), Mode_Receive_File_Data);
		QCOMPARE(*vReceiver.ForTestGetReveiveBuffer(), *(new QByteArray()));
}

QTEST_APPLESS_MAIN(DataMethodsTests)

#include "DataMethodsTests.moc"
