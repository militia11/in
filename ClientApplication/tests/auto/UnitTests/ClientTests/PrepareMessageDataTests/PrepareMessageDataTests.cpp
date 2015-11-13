#include <QString>
#include <QtTest>

#include "src/libs/controllers/CClient.h"
#include "src/libs/dao/CRepository.h"

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
		CClient vClient;
    u_int16_t vChecksum = 384;
    QByteArray vResultData = vClient.PrepareMessageData(vChecksum);
    QByteArray vExpectedData(">>384<");

		QCOMPARE(vResultData, vExpectedData);
}

QTEST_APPLESS_MAIN(PrepareMessageDataTests)

#include "PrepareMessageDataTests.moc"
