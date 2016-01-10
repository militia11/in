#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "tests/auto/UnitTests/testlibs/CReceiverWrapper.h"

class ConnectionTests : public QObject {
    Q_OBJECT

  public:
    ConnectionTests();

  private Q_SLOTS:
    void TestConnectMethod();
    void TestConnectMethodNullSocket();
    void TestGetSocket();
    void TestGetNullSocket();
    void TestDisconnectedMethodDeleteLaterSocket();
    void TestDisconnectedMethodDeleteBuffer();
    void TestDisconnectedMethodDeleteDataSize();
    void TestDisconnectedMethodDeleteAllPointers();
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

void ConnectionTests::TestDisconnectedMethodDeleteLaterSocket() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetSocket(new QTcpSocket());
    vReceiver.ForTestDisconnected();

    // Because deletelater slot from QObject
    QVERIFY(vReceiver.ForTestGetSocket());
}

void ConnectionTests::TestDisconnectedMethodDeleteBuffer() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetReceiveBuffer(new QByteArray());
    vReceiver.ForTestDisconnected();

    QEXPECT_FAIL("", "mReceiveBuffer powinien być pustym wskaźnikiem", Continue);
    QVERIFY(vReceiver.ForTestGetReveiveBuffer());
}

void ConnectionTests::TestDisconnectedMethodDeleteDataSize() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetDataSize(new int32_t(25));
    vReceiver.ForTestDisconnected();

    QEXPECT_FAIL("", "mDataSize powinien być pustym wskaźnikiem", Continue);
    QVERIFY(vReceiver.ForTestGetDataSize());
}

void ConnectionTests::TestDisconnectedMethodDeleteAllPointers() {
    CReceiverWrapper vReceiver;

    vReceiver.ForTestSetSocket(new QTcpSocket());
    vReceiver.ForTestSetReceiveBuffer(new QByteArray());
    vReceiver.ForTestSetDataSize(new int32_t(25));

    vReceiver.ForTestDisconnected();

    QVERIFY(vReceiver.ForTestGetSocket());

    QEXPECT_FAIL("", "mReceiveBuffer powinien być pustym wskaźnikiem", Continue);
    QVERIFY(vReceiver.ForTestGetReveiveBuffer());

    QEXPECT_FAIL("", "mDataSize powinien być pustym wskaźnikiem", Continue);
    QVERIFY(vReceiver.ForTestGetDataSize());
}

QTEST_MAIN(ConnectionTests)

#include "ConnectionTests.moc"
