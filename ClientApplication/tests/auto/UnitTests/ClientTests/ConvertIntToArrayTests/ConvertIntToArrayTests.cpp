#include <QString>
#include <QtTest>

#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlib/CClientWrapper.h"

class ConvertIntToArrayTests : public QObject {
    Q_OBJECT

  public:
    ConvertIntToArrayTests();

  private Q_SLOTS:
    void TestConvertIntToArrayTest();
};

ConvertIntToArrayTests::ConvertIntToArrayTests() {}

void ConvertIntToArrayTests::TestConvertIntToArrayTest() {
    CClientWrapper vClient(new QTcpSocket);

		int32_t vNumber {12};
    QByteArray vConvertedData = vClient.ForTestIntToArray(vNumber);
		QDataStream vStream(&vConvertedData, QIODevice::ReadWrite);
		vStream << vNumber;

		QCOMPARE(qPrintable(QString(vConvertedData.toHex().toUpper())), "0000000C");

    // Qt 5.4 have function toStdString which is ideal for this compare
		// but it is not compatibile with Qt MySql driver
}

QTEST_APPLESS_MAIN(ConvertIntToArrayTests)

#include "ConvertIntToArrayTests.moc"
