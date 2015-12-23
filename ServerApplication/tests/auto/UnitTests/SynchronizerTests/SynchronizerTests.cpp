#include <QString>
#include <QtTest>

class SynchronizerTests : public QObject
{
    Q_OBJECT

  public:
    SynchronizerTests();

  private Q_SLOTS:
    void test();
};void EmptyNewData();

/**
 * @brief Test single incomming message at once
 */
void SimpleSingleMessage();

/**
 * @brief Test complicated example
 *
 * First incomming data: half of first message
 * Second incomming data: rest of first message, rubbish and full second
 * message
 * Third incomming data: half of third message
 *
 * Synchronizer should return two complete messages
 */
void ComplicatedExample();
// Copyright 2015 WB Electronics S.A.

#include "CGODSynchronizerTest.h"

#include "../CGODSynchronizer.h"

void CGODSynchronizerTest::EmptyNewData() {
  CGODSynchronizer vSynchronizer;
  const QByteArray vEmptyIncommingData;

  QList<QByteArray> vActualNewMessages =
    vSynchronizer.SynchronizeMessages(vEmptyIncommingData);
  QCOMPARE(vActualNewMessages.length(), 0);
}

void CGODSynchronizerTest::SimpleSingleMessage() {
  CGODSynchronizer vSynchronizer;
  QByteArray vSingleMessageData(">D0004001007");
  vSingleMessageData += QByteArray::fromHex("0D0A");

  QList<QByteArray> vActualNewMessages =
    vSynchronizer.SynchronizeMessages(vSingleMessageData);
  QCOMPARE(vActualNewMessages.length(), 1);

  QByteArray vExpectedMessage = vSingleMessageData;
  QCOMPARE(vActualNewMessages.at(0), vExpectedMessage);
}

void CGODSynchronizerTest::ComplicatedExample() {
  CGODSynchronizer vSynchronizer;

  // Half of first message
  QByteArray vFirstData(">D00040");
  QList<QByteArray> vActualNewMessages0 =
    vSynchronizer.SynchronizeMessages(vFirstData);
  QCOMPARE(vActualNewMessages0.length(), 0);

  // Rest of first message, rubbish and full second messages
  QByteArray vSecondData("01007");
  vSecondData += QByteArray::fromHex("0D0A");
  vSecondData += ">rubbish";
  vSecondData += ">D00050070016F";
  vSecondData += QByteArray::fromHex("0D0A");
  QList<QByteArray> vActualNewMessages1 =
    vSynchronizer.SynchronizeMessages(vSecondData);
  QCOMPARE(vActualNewMessages1.length(), 2);

  QByteArray vExpectedFirstMessage(">D0004001007");
  vExpectedFirstMessage += QByteArray::fromHex("0D0A");
  QCOMPARE(vActualNewMessages1.at(0), vExpectedFirstMessage);

  QByteArray vExpectedSecondMessage(">D00050070016F");
  vExpectedSecondMessage += QByteArray::fromHex("0D0A");
  QCOMPARE(vActualNewMessages1.at(1), vExpectedSecondMessage);

  // Half of third message
  QByteArray vThirdData(">T0006");
    QList<QByteArray> vActualNewMessages2 =
    vSynchronizer.SynchronizeMessages(vThirdData);
  QCOMPARE(vActualNewMessages2.length(), 0);
}


SynchronizerTests::SynchronizerTests()
{
}

void SynchronizerTests::test()
{
  QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(SynchronizerTests)

#include "SynchronizerTests.moc"
