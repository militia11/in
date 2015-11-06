#include <QString>
#include <QtTest>

#include "src/libs/controllers/CReceiverWrapper.h"

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
		CReceiverWrapper vReceiver;
		char vMessage[] {">>645<"};

		// Char array have one more sign - end
		size_t vMessageSize = sizeof(vMessage) - 1;
		vReceiver.TestSetMessageSize(vMessageSize);

		QVERIFY(vReceiver.TestHasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestWrongBeginMessageFirstChar() {
		CReceiverWrapper vReceiver;
		char vMessage[] {"1>71>"};

		size_t vMessageSize = sizeof(vMessage) - 1;
		vReceiver.TestSetMessageSize(vMessageSize);

		QEXPECT_FAIL("", "Zły format wiadomości", Continue);
		QVERIFY(vReceiver.TestHasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestWrongBeginMessageSecondChar() {
		CReceiverWrapper vReceiver;
		char vMessage[] {">a84>"};

		size_t vMessageSize = sizeof(vMessage) - 1;
		vReceiver.TestSetMessageSize(vMessageSize);

		QEXPECT_FAIL("", "Zły format wiadomości", Continue);
		QVERIFY(vReceiver.TestHasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestWrongEndMessageChar() {
		CReceiverWrapper vReceiver;
		char vMessage[] {">>74s"};

		size_t vMessageSize = sizeof(vMessage) - 1;
		vReceiver.TestSetMessageSize(vMessageSize);

		QEXPECT_FAIL("", "Zły format wiadomości", Continue);
		QVERIFY(vReceiver.TestHasMessageCorrectFormat(vMessage));
}

void MessageFormatTests::TestChecksumIsNotDigit() {
		CReceiverWrapper vReceiver;
		char vMessage[] {">>6s3>"};

		size_t vMessageSize = sizeof(vMessage) - 1;
		vReceiver.TestSetMessageSize(vMessageSize);

		QEXPECT_FAIL("", "Zły format wiadomości", Continue);
		QVERIFY(vReceiver.TestHasMessageCorrectFormat(vMessage));
}
QTEST_APPLESS_MAIN(MessageFormatTests)

#include "MessageFormatTests.moc"
