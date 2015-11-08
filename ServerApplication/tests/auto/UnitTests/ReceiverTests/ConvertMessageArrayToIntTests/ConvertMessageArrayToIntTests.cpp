#include <QString>
#include <QtTest>

#include "tests/auto/UnitTests/testlibs/CReceiverWrapper.h"

/**
 * @brief The ConvertMessageArrayToIntTests class
 *
 * Only correct message posible because previously we check message in
 * HasMessageCorrectFormat funtion
 */
class ConvertMessageArrayToIntTests : public QObject {
    Q_OBJECT

  public:
    ConvertMessageArrayToIntTests();

  private Q_SLOTS:
		void TestMessageSize();
    void TestConvertCorrectMessageThreeDigit();
    void TestConvertCorrectMessageSixDigit();
};

ConvertMessageArrayToIntTests::ConvertMessageArrayToIntTests() {
}

void ConvertMessageArrayToIntTests::TestMessageSize() {
		CReceiverWrapper vReceiver;

		char vMessage[] {">>13586<"};
		int vExpectedMessageSize {sizeof(vMessage) - 1};

		vReceiver.ForTestSetMessageSize(vExpectedMessageSize);

		int vMessageSizeFromReceiver {vReceiver.ForTestGetMessageSize()};
		QCOMPARE(vMessageSizeFromReceiver, vExpectedMessageSize);
}

void ConvertMessageArrayToIntTests::TestConvertCorrectMessageThreeDigit() {
		CReceiverWrapper vReceiver;

		char vMessage[] {">>386<"};
		int vMessageSize {sizeof(vMessage) - 1};
		vReceiver.ForTestSetMessageSize(vMessageSize);
		vReceiver.ForTestSetMessage(vMessage);

		int vResult {vReceiver.ForTestConvertMessageArrayToInt()};
		int vExpected {386};
		QCOMPARE(vResult, vExpected);
}

void ConvertMessageArrayToIntTests::TestConvertCorrectMessageSixDigit() {
	CReceiverWrapper vReceiver;

	char vMessage[] {">>12516<"};
	int vMessageSize {sizeof(vMessage) - 1};
	vReceiver.ForTestSetMessageSize(vMessageSize);
	vReceiver.ForTestSetMessage(vMessage);

	int vResult {vReceiver.ForTestConvertMessageArrayToInt()};
	int vExpected {12516};
	QCOMPARE(vResult, vExpected);
}

QTEST_APPLESS_MAIN(ConvertMessageArrayToIntTests)

#include "ConvertMessageArrayToIntTests.moc"
