#include <QString>
#include <QtTest>

#include "tests/auto/UnitTests/testlibs/CalculateChecksumHelper.h"
#include "tests/auto/UnitTests/testlibs/CReceiverWrapper.h"

class CalculateChecksumTests : public QObject {
    Q_OBJECT

  public:
    CalculateChecksumTests();

  private Q_SLOTS:
    void CalculateByteArrayOneSign();
    void CalculateByteArrayTwoSigns();
    void CalculateLongByteArray();
    // inne wariacje
};

CalculateChecksumTests::CalculateChecksumTests() {
}

void CalculateChecksumTests::CalculateByteArrayOneSign() {
    CReceiverWrapper vReceiver;

    QByteArray vData("11");
    u_int16_t vResult {vReceiver.ForTestCalculateFileDataChecksum(vData)};

    // {98};  // ( (16+16+16)*2 ) + 2
    // 2 is (1 + 1)
    u_int16_t vExpected {CalculateChecksumHelper::CalculateFileDataChecksum(vData)};
    QVERIFY(vExpected == 98);
    QCOMPARE(vResult, vExpected);
}

void CalculateChecksumTests::CalculateByteArrayTwoSigns() {
    CReceiverWrapper vReceiver;

    QByteArray vData("213");
    u_int16_t vResult {vReceiver.ForTestCalculateFileDataChecksum(vData)};

    // {150};  // ( (16+16+16)*4 ) + 6
    // 6 is (2 + 1 + 3)
    u_int16_t vExpected {CalculateChecksumHelper::CalculateFileDataChecksum(vData)};
    QVERIFY(vExpected == 150);
    QCOMPARE(vResult, vExpected);
}

void CalculateChecksumTests::CalculateLongByteArray() {

    CReceiverWrapper vReceiver;

    QByteArray vData("1211");
    u_int16_t vResult {vReceiver.ForTestCalculateFileDataChecksum(vData)};

    u_int16_t vExpected {CalculateChecksumHelper::CalculateFileDataChecksum(vData)};
    // {197};  // ( (16+16+16)*4 ) + 5

    // 5 is (1 + 2 + 1 + 1)
    QVERIFY(vExpected == 197);
    QCOMPARE(vResult, vExpected);
}

QTEST_APPLESS_MAIN(CalculateChecksumTests)

#include "CalculateChecksumTests.moc"
