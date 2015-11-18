#include <QString>
#include <QtTest>

#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlib/CClientWrapper.h"

extern CRepository gRepository;

class PrepareMessageDataTests : public QObject {
    Q_OBJECT

  public:
		PrepareMessageDataTests();

  private Q_SLOTS:
		void TestPrepareMessageData();
};

PrepareMessageDataTests::PrepareMessageDataTests() {
}

void PrepareMessageDataTests::TestPrepareMessageData() {
    CClientWrapper vClient(new QTcpSocket);
		int16_t vChecksum = 384;
		QByteArray vResultData = vClient.ForTestPrepareMessageData(vChecksum);
    QByteArray vExpectedData(">>384<");

    QCOMPARE(vResultData, vExpectedData);
}

QTEST_APPLESS_MAIN(PrepareMessageDataTests)

#include "PrepareMessageDataTests.moc"
