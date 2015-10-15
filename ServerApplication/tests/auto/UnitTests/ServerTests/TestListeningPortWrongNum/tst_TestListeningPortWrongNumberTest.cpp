#include <QString>
#include <QtTest>

#include "libs/controllers/CServer.h"

class TestListeningPortWrongNumberTest : public QObject {
    Q_OBJECT

  public:
    TestListeningPortWrongNumberTest();

  private Q_SLOTS:
    void testCase();
};

TestListeningPortWrongNumberTest::TestListeningPortWrongNumberTest() {
}

void TestListeningPortWrongNumberTest::testCase() {
    // Verify status of listening
    CServer *vServer = new CServer;
    quint16 vPortNum = 21; // wrong number

    bool vIsListen = vServer->listen(QHostAddress::Any, vPortNum);

    QEXPECT_FAIL("", "Serwer nie powinien wystartować na podanym numerze portu"
                 "Za mała liczba", Continue);
    QVERIFY(vIsListen);
}

QTEST_APPLESS_MAIN(TestListeningPortWrongNumberTest)

#include "tst_TestListeningPortWrongNumberTest.moc"
