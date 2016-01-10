#include <QString>
#include <QtTest>

#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlibs/CReceiverWrapper.h"
#include "tests/auto/UnitTests/testlibs/CQTcpSocketMockInServer.h"

extern CRepository gRepository;

class DataMethodsTests : public QObject {
    Q_OBJECT

  public:
    DataMethodsTests();

  private Q_SLOTS:
    void TestRemoveSizeFromBuffer();
    void TestHasDataReceivedCompletelyMethod();
    void TestHasDataReceivedCompletelyMethodTDataSizeAboveBufferExpectFalse();
    void TestHasDataReceivedCompletelyMethodTDataSizeBelow0ExpectFalse();
    void TestHasDataReceivedCompletelyMethodTDataSizeEqual0ExpectFalse();
    void TestHasSizeOfDataReceivedCompletelyMethod();
    void TestHasSizeOfDataReceivedCompletelyMethodDataSizeIsNotZero();
    void TestHasSizeOfDataReceivedCompletelyMethodBufferLess4();
    void TestNewDataMethod();
    void TestRouteDataMethod();
    void TestRouteDataPreventBufferOverflow();
    void TestRouteDataSpecifySign();
    void TestServeReceivedMessageWrongMessageFormat();
    void TestServeReceivedMessageChangeAllParam();
    void TestServeReceivedMessageChangeMinimumToExecution();
    void TestServeReceivedFileData();

};

DataMethodsTests::DataMethodsTests() {
}

void DataMethodsTests::TestRemoveSizeFromBuffer() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));  // size is 9
    vReceiver.ForTestRemoveSizeFromBuffer();
    QCOMPARE(*vReceiver.ForTestGetReveiveBuffer(),
             QByteArray(" data"));  //should remove first 4 bytes
}

void DataMethodsTests::TestHasDataReceivedCompletelyMethod() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t {1});
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));  // size() == 9
    QVERIFY(vReceiver.ForTestHasDataReceivedCompletely());
}

void DataMethodsTests::TestHasDataReceivedCompletelyMethodTDataSizeAboveBufferExpectFalse() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t {10});
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));
    QVERIFY(vReceiver.ForTestHasDataReceivedCompletely() == false);
}

void DataMethodsTests::TestHasDataReceivedCompletelyMethodTDataSizeBelow0ExpectFalse() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t { -1});
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));
    QVERIFY(vReceiver.ForTestHasDataReceivedCompletely() == false);
}

void DataMethodsTests::TestHasDataReceivedCompletelyMethodTDataSizeEqual0ExpectFalse() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t {}); // is 0
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test data"));
    QVERIFY(vReceiver.ForTestHasDataReceivedCompletely() == false);
}

void DataMethodsTests::TestHasSizeOfDataReceivedCompletelyMethod() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t {}); // is 0
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("SIZE"));  // size have 4 bytes
    QVERIFY(vReceiver.ForTestHasSizeOfDataReceivedCompletely());
}

void DataMethodsTests::TestHasSizeOfDataReceivedCompletelyMethodDataSizeIsNotZero() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t {2});
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("SIZE"));
    QVERIFY(vReceiver.ForTestHasSizeOfDataReceivedCompletely() == false);
}

void DataMethodsTests::TestHasSizeOfDataReceivedCompletelyMethodBufferLess4() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t {});
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("ttt"));  // size have 4 bytes
    QVERIFY(vReceiver.ForTestHasSizeOfDataReceivedCompletely() == false);
}

void DataMethodsTests::TestNewDataMethod() {
    CReceiverWrapper vReceiver;

    CQTcpSocketMockInServer *vSocketMock {new CQTcpSocketMockInServer()};
    vReceiver.ForTestSetSocket(vSocketMock);

    vReceiver.ForTestSetReceiveBuffer(new QByteArray());
    vReceiver.ForTestNewData();

    QString vExpectedLog("->bytesAvailable()");
    QCOMPARE(vSocketMock->GetLog(), vExpectedLog);
}

void DataMethodsTests::TestRouteDataMethod() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetReceiveDataMode(Mode_Receive_File_Checksum);
    QCOMPARE(vReceiver.ForTestGetReceiveByteCount(), 0);

    char vExpectedChar {'X'};
    vReceiver.ForTestRouteData(vExpectedChar);

    // Verify if in mMessageFileChecksum[mReceiveByteCount] is set char
    QCOMPARE(*vReceiver.ForTestGetMessageFileChecksum(), vExpectedChar);
    // mReceiveByteCount is ++;
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
    char vSign {'<'};
    vReceiver.ForTestSetReceiveBuffer(new QByteArray("Test Data"));
    vReceiver.ForTestSetReceiveByteCount(1);
    // Message size before call function RouteData
    QCOMPARE(vReceiver.ForTestGetMessageSize(), 0);

    vReceiver.ForTestRouteData(vSign);

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
