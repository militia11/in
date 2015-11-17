#include <QString>
#include <QtTest>

#include "tests/auto/UnitTests/testlibs/CalculateChecksumHelper.h"
#include "tests/auto/UnitTests/testlibs/CReceiverWrapper.h"

class CalculateChecksumTests : public QObject {
		Q_OBJECT

	public:
		CalculateChecksumTests();

	private Q_SLOTS:
		void CalculateShortByteArray();
		void CalculateLongByteArray();
		// inne wariacje
};

CalculateChecksumTests::CalculateChecksumTests() {
}

void CalculateChecksumTests::CalculateShortByteArray() {
		CReceiverWrapper vReceiver;

		QByteArray vData("11");
		u_int16_t vResult {vReceiver.ForTestCalculateFileDataChecksum(vData)};

    u_int16_t vExpected {CalculateChecksumHelper::CalculateFileDataChecksum(vData)};
    //{98};  // ( (16+16+16)*2 ) + 2

		QCOMPARE(vResult, vExpected);
}

void CalculateChecksumTests::CalculateLongByteArray()
{
  QVERIFY(false);
}

QTEST_APPLESS_MAIN(CalculateChecksumTests)

#include "CalculateChecksumTests.moc"
