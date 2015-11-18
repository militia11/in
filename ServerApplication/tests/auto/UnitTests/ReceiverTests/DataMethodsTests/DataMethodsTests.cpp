#include <QString>
#include <QtTest>

#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlibs/CReceiverWrapper.h"

//#include "src/libs/controllers/CStorePhotoTransaction.h"

extern CRepository gRepository;

class DataMethodsTests : public QObject {
		Q_OBJECT

	public:
		DataMethodsTests();

	private Q_SLOTS:
		void TestNewDataMethod();
		void TestRouteDataMethod();
		void TestRouteDataPreventBufferOverflow();
		void TestRouteDataSpecifySign();
		void TestServeReceivedMessageWrongMessageFormat();
		void TestServeReceivedMessageChangeAllParam();
		void TestServeReceivedMessageChangeMinimumToExecution();
		void TestServeReceivedMessageChangeMinimumResponeToClient();
		void TestServeReceivedFileData();
};

DataMethodsTests::DataMethodsTests() {
}

void DataMethodsTests::TestNewDataMethod() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetSocket(new QTcpSocket);
		vReceiver.ForTestNewData();
		QVERIFY(false);
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

void DataMethodsTests::TestServeReceivedMessageWrongMessageFormat() {
		CReceiverWrapper vReceiver;

		char vMessage[] {"5>>645<"};
		// Char array have one more sign - end
		size_t vMessageSize {sizeof(vMessage) - 1};
		vReceiver.ForTestSetMessageSize(vMessageSize);
		vReceiver.ForTestSetMessage(vMessage);

		bool vPass = false;

		try {
				vReceiver.ForTestServeReceivedMessage();
		} catch (std::runtime_error vException) {
				vPass = true;
		}

		QVERIFY(vPass);
}

void DataMethodsTests::TestServeReceivedMessageChangeAllParam() {
		CReceiverWrapper vReceiver;

		vReceiver.ForTestSetSocket(new QTcpSocket());
		char vMessage[] {">>645<"};
		size_t vMessageSize {sizeof(vMessage) - 1};
		vReceiver.ForTestSetMessageSize(vMessageSize);
		vReceiver.ForTestSetMessage(vMessage);
		vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));
		gRepository.RefreshChecksums();

		vReceiver.ForTestSetDataSize(new int32_t(50));
		vReceiver.ForTestSetReceiveByteCount(100);
		vReceiver.ForTestServeReceivedMessage();

		QCOMPARE(*vReceiver.ForTestGetDataSize(), 0);
		QCOMPARE(vReceiver.ForTestGetMessageSize(), 0);
		QCOMPARE(vReceiver.ForTestGetReceiveByteCount(), 0);
		QCOMPARE(*vReceiver.ForTestGetReveiveBuffer(), QByteArray());
}

void DataMethodsTests::TestServeReceivedMessageChangeMinimumToExecution() {
		CReceiverWrapper vReceiver;


		vReceiver.ForTestSetSocket(new QTcpSocket());
		char vMessage[] {">>1876<"};
		size_t vMessageSize {sizeof(vMessage) - 1};
		vReceiver.ForTestSetMessageSize(vMessageSize);
		vReceiver.ForTestSetMessage(vMessage);
		vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));
		gRepository.RefreshChecksums();

		vReceiver.ForTestServeReceivedMessage();

		QCOMPARE(vReceiver.ForTestGetMessageSize(), 0);
		QCOMPARE(*vReceiver.ForTestGetReveiveBuffer(), QByteArray());
}

void DataMethodsTests::TestServeReceivedMessageChangeMinimumResponeToClient() {
		CReceiverWrapper vReceiver;
		vReceiver.ForTestSetSocket(new QTcpSocket);
		char vMessage[] {">>649<"};
		size_t vMessageSize {sizeof(vMessage) - 1};
		vReceiver.ForTestSetMessageSize(vMessageSize);
		vReceiver.ForTestSetMessage(vMessage);
		vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));
		gRepository.RefreshChecksums();

		vReceiver.ForTestServeReceivedMessage();

		QCOMPARE(vReceiver.ForTestGetMessageSize(), 0);
		QCOMPARE(*vReceiver.ForTestGetReveiveBuffer(), QByteArray());
		/*
			CTcpSocketMock *vTcpSocketMockFromReceiver =
					dynamic_cast<CTcpSocketMock *>(vReceiver.GetSocket());
			QString vExpectedLog = "->write(SEND)";
			QCOMPARE(vTcpSocketMockFromReceiver->GetLog(), vExpectedLog);

		jak dziala dodac tez do allParamtest*/
}

void DataMethodsTests::TestServeReceivedFileData() {
		gRepository.SetSettings("sqlite3",
														"database=:memory:");
		gRepository.Connect();
		gRepository.PopulateDatabase();
		CReceiverWrapper vReceiver;

		QByteArray *vData {new QByteArray("Test data")};

		vReceiver.ForTestSetDataSize(new int32_t(9));
		vReceiver.ForTestSetReceiveBuffer(vData);

		vReceiver.ForTestServeReceivedFileData();
																								///@todo
		CRetrievePhotoTransaction vRetrieveTransaction(858);
		vRetrieveTransaction.Execute();

		QByteArray vRetrievedData = vRetrieveTransaction.GetData();
		QCOMPARE(vRetrievedData, QByteArray("Test data"));
}

QTEST_APPLESS_MAIN(DataMethodsTests)

#include "DataMethodsTests.moc"
