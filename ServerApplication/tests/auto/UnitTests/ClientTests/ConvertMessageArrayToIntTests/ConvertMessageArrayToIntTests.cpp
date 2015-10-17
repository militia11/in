#include <QString>
#include <QtTest>

#include "libs/testssupport/CClientWrapper.h"

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
	CClientWrapper vClient;
	char *vMessage = ">>386<";
	int vSize = 6;
	// vClient.mMessageFileChecksum = ;
	vClient.TestSetMessageSize(vSize);

	int res = vClient.TestGetMessageSize();
	QCOMPARE(res, 6);

	//int vResult = vClient.ConvertMessageArrayToInt();
	//int vExpected = 386;

	//QCOMPARE(vResult, vExpected);
}

void ConvertMessageArrayToIntTests::TestConvertCorrectMessageSixDigit() {
	/*CClient vClient;
	vClient.mMessageFileChecksum = ">>12516<";
	vClient.mMessageSize = 6;

	int vResult = vClient.ConvertMessageArrayToInt();
	int vExpected = 12516;

	QCOMPARE(vResult, vExpected);*/
}

QTEST_APPLESS_MAIN(ConvertMessageArrayToIntTests)

#include "ConvertMessageArrayToIntTests.moc"
