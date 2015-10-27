#include <QString>
#include <QtTest>

#include "libs/controllers/CReceiver.h"

class MessageFormatTests : public QObject {
    Q_OBJECT

  public:
    MessageFormatTests();

  private Q_SLOTS:
    void TestCorrectMessageFormat();
    void TestWrongBeginMessageFirstChar();
    void TestWrongBeginMessageSecondChar();
    void TestWrongEndMessageChar();
    void TestChecksumIsNotDigit();
};

MessageFormatTests::MessageFormatTests() {
}

void MessageFormatTests::TestCorrectMessageFormat() {
    CReceiver vClient;
    char *vMessage = ">>635>";

    //	QVERIFY(vClient.HasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestWrongBeginMessageFirstChar() {
    CReceiver vClient;
    char *vMessage = "1>71>";

    //QEXPECT_FAIL("", "Zły format wiadomości", Continue);
    //QVERIFY(vClient.HasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestWrongBeginMessageSecondChar() {
    CReceiver vClient;
    char *vMessage = ">a84>";

    //QEXPECT_FAIL("", "Zły format wiadomości", Continue);
    //QVERIFY(vClient.HasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestWrongEndMessageChar() {
    CReceiver vClient;
    char *vMessage = ">>74s";

    //QEXPECT_FAIL("", "Zły format wiadomości", Continue);
    //QVERIFY(vClient.HasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestChecksumIsNotDigit() {
    CReceiver vClient;
    char *vMessage = ">>6s3>";

    //QEXPECT_FAIL("", "Zły format wiadomości", Continue);
    //QVERIFY(vClient.HasMessageCorrectFormat(vMessage));
}

QTEST_APPLESS_MAIN(MessageFormatTests)

#include "tst_MessageFormatTests.moc"
