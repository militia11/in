#include <QString>
#include <QtTest>

#include "libs/controllers/CClient.h"
/**
 * @brief The ConvertMessageArrayToIntTests class
 *
 * Only correct message posible because previously we check message in
 * HasMessageCorrectFormat funtion.
 */
class ConvertMessageArrayToIntTests : public CClient {
		Q_OBJECT

	public:
		ConvertMessageArrayToIntTests();

	private Q_SLOTS:
		void TestConvertCorrectMessageThreeDigit();
		void TestConvertCorrectMessageSixDigit();
};

ConvertMessageArrayToIntTests::ConvertMessageArrayToIntTests() {
}

void ConvertMessageArrayToIntTests::TestConvertCorrectMessageThreeDigit() {
	CClient vClient;
	vClient.mMessageFileChecksum = ">>386<";
	vClient.mMessageSize = vClient.mMessageFileChecksum.size();
	////////////////////////////////////////////////////

	int vResult = vClient.ConvertMessageArrayToInt();
	int vExpected = 386;

	QCOMPARE(vResult, vExpected);
}

void ConvertMessageArrayToIntTests::TestConvertCorrectMessageSixDigit() {
	CClient vClient;
	vClient.mMessageFileChecksum = ">>12516<";
	vClient.mMessageSize = vClient.mMessageFileChecksum.size();
	////////////////////////////////////////////////////

	int vResult = vClient.ConvertMessageArrayToInt();
	int vExpected = 12516;

	QCOMPARE(vResult, vExpected);
}

QTEST_APPLESS_MAIN(ConvertMessageArrayToIntTests)

#include "ConvertMessageArrayToIntTests.moc"
