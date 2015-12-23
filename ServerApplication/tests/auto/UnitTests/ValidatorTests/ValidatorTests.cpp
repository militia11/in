#include <QString>
#include <QtTest>

class ValidatorTests : public QObject
{
    Q_OBJECT

  public:
    ValidatorTests();

  private Q_SLOTS:
    void test();
    /**
     * @brief Test calculating checksum for empty message
     *
     * For empty message sum of bytes is 0x00 so checksum should be also
     * 0x00
     */
    void TestCalculateChecksumEmptyMessage();

    /**
     * @brief Test calculating checksum for normal message
     */
    void TestCalculateChecksumNormalMessage();

    /**
     * @brief Test validation of checksum of correct message
     */
    void TestChecksumValidatorCorrect();

    /**
     * @brief Test validation of checksum of incorrect message
     */
    void TestChecksumValidatorIncorrect();

    /**
     * @brief Test validation of checksum of empty message
     */
    void TestChecksumValidatorEmpty();

    /**
     * @brief Test validation of checksum of message with non-ascii
     *        checksum
     */
    void TestChecksumValidatorNonAsciiChecksum();

    /**
     *	Test validation of correct format message
     */
    void TestHasMessageCorrectFormatCorrect();

    /**
     *	Test validation of to short message
     */
    void TestHasMessageCorrectFormatToShort();

    /**
     *	Test validation of messege without synchronization char
     */
    void TestHasMessageCorrectFormatWithoutSyncChar();

    /**
     *	Test validation of submodule letter of message
     */
    void TestHasMessageCorrectFormatSubmoduleLetter();

    /**
     *	Test validation of CRLF of message
     */
    void TestHasMessageCorrectFormatCRLF();

    /**
     *	Test validation of Hex format message
     */
    void TestHasMessageCorrectFormatHex();
};
// Copyright 2015 WB Electronics S.A.

#include "CGODValidatorTest.h"

#include <stdint.h>

#include "../CGODValidator.h"

void CGODValidatorTest::TestCalculateChecksumEmptyMessage() {
  CGODValidator vValidator;
  QByteArray vEmptyMessage;

  uint8_t vExpectedChecksum = 0;
  uint8_t vActualChecksum = vValidator.CalculateChecksum(
    vEmptyMessage);

  QCOMPARE(vActualChecksum, vExpectedChecksum);
}

void CGODValidatorTest::TestCalculateChecksumNormalMessage() {
  CGODValidator vValidator;
  QByteArray vNormalMessagePositive =
    QByteArray::fromHex("05 2f ab 54 00 01");
  // SUM = 0x134, less significant byte is 0x34
  uint8_t vExpectedChecksumPositive = 0x34;
  uint8_t vActualChecksumPositive =
    vValidator.CalculateChecksum(vNormalMessagePositive);
  QCOMPARE(vActualChecksumPositive, vExpectedChecksumPositive);

  QByteArray vNormalMessageNegative =
    QByteArray::fromHex("05 2f ab 54 60 01");
  // SUM = 0x194, less significant byte is 0x94
  uint8_t vExpectedChecksumNegative = 0x94;
  uint8_t vActualChecksumNegative =
    vValidator.CalculateChecksum(vNormalMessageNegative);

  QCOMPARE(vActualChecksumNegative, vExpectedChecksumNegative);
}

void CGODValidatorTest::TestChecksumValidatorCorrect() {
  CGODValidator vValidator;

  QByteArray vMessage(">D0004001007");
  vMessage += QByteArray::fromHex("0D0A");

  bool vActualChecksumCorrect =
    vValidator.HasMessageCorrectChecksum(vMessage);
  QCOMPARE(vActualChecksumCorrect, true);
}

void CGODValidatorTest::TestChecksumValidatorIncorrect() {
  CGODValidator vValidator;

  QByteArray vMessage(">D0004001009");
  vMessage += QByteArray::fromHex("0D0A");

  bool vActualChecksumCorrect =
    vValidator.HasMessageCorrectChecksum(vMessage);
  QCOMPARE(vActualChecksumCorrect, false);
}

void CGODValidatorTest::TestChecksumValidatorEmpty() {
  CGODValidator vValidator;

  QByteArray vEmptyMessage;

  bool vActualChecksumCorrect =
    vValidator.HasMessageCorrectChecksum(vEmptyMessage);
  QCOMPARE(vActualChecksumCorrect, false);
}

void CGODValidatorTest::TestChecksumValidatorNonAsciiChecksum() {
  CGODValidator vValidator;

  QByteArray vMessage(">D000400100G");
  vMessage += QByteArray::fromHex("0D0A");

  bool vActualChecksumCorrect =
    vValidator.HasMessageCorrectChecksum(vMessage);
  QCOMPARE(vActualChecksumCorrect, false);
}

void CGODValidatorTest::TestHasMessageCorrectFormatCorrect() {
  CGODValidator vValidator;

  QByteArray vCorrectMessage(">D0004001007");
  vCorrectMessage += QByteArray::fromHex("0D0A");

  bool vActualMessageCorrect =
    vValidator.HasMessageCorrectFormat(vCorrectMessage);

  QCOMPARE(vActualMessageCorrect, true);
}

void CGODValidatorTest::TestHasMessageCorrectFormatToShort() {
  CGODValidator vValidator;

  QByteArray vToShortMessage(">D000");

  bool vActualMessageCorrect =
    vValidator.HasMessageCorrectFormat(vToShortMessage);

  QCOMPARE(vActualMessageCorrect, false);
}

void CGODValidatorTest::TestHasMessageCorrectFormatWithoutSyncChar() {
  CGODValidator vValidator;

  QByteArray vWithoutSyncCharMessage("?D0004001008");
  vWithoutSyncCharMessage += QByteArray::fromHex("0D0A");

  bool vActualMessageCorrect =
    vValidator.HasMessageCorrectFormat(vWithoutSyncCharMessage);

  QCOMPARE(vActualMessageCorrect, false);
}

void CGODValidatorTest::TestHasMessageCorrectFormatSubmoduleLetter() {
  CGODValidator vValidator;

  QByteArray vSubmoduleLetterMessage(">E0004001008");
  vSubmoduleLetterMessage += QByteArray::fromHex("0D0A");

  bool vActualMessageCorrect =
    vValidator.HasMessageCorrectFormat(vSubmoduleLetterMessage);

  QCOMPARE(vActualMessageCorrect, false);
}

void CGODValidatorTest::TestHasMessageCorrectFormatCRLF() {
  CGODValidator vValidator;

  // CR
  QByteArray vNoCRMessage(">D0004001007");
  vNoCRMessage += QByteArray::fromHex("000A");

  bool vActualMessageCorrect0 =
    vValidator.HasMessageCorrectFormat(vNoCRMessage);

  QCOMPARE(vActualMessageCorrect0, false);

  // LF
  QByteArray vNoLFMessage(">D0004001007");
  vNoLFMessage += QByteArray::fromHex("0D00");

  bool vActualMessageCorrect1 =
    vValidator.HasMessageCorrectFormat(vNoLFMessage);

  QCOMPARE(vActualMessageCorrect1, false);
}

void CGODValidatorTest::TestHasMessageCorrectFormatHex() {
  CGODValidator vValidator;

  QByteArray vFormatHexMessage(">D0G0400101E");
  vFormatHexMessage += QByteArray::fromHex("0D0A");

  bool vActualMessageCorrect =
    vValidator.HasMessageCorrectFormat(vFormatHexMessage);

  QCOMPARE(vActualMessageCorrect, false);
}




ValidatorTests::ValidatorTests()
{
}

void ValidatorTests::test()
{
  QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ValidatorTests)

#include "ValidatorTests.moc"
