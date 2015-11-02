#include <QString>
#include <QtTest>

#include "src/libs/controllers/CClient.h"
#include "src/libs/dao/CRepository.h"

extern CRepository gRepository;

class PrepareMessageData : public QObject {
    Q_OBJECT

  public:
    PrepareMessageData();

  private Q_SLOTS:
    void TestPrepareMessageData();
};

PrepareMessageData::PrepareMessageData() {
}

void PrepareMessageData::TestPrepareMessageData() {
    CReceiver vClient;
    u_int16_t vChecksum = 384;
    QByteArray vResultData = vClient.PrepareMessageData(vChecksum);
    QByteArray vExpectedData(">>384<");

    QCOMPARE(vResultData, vExpectedData);
}

QTEST_APPLESS_MAIN(PrepareMessageData)

#include "tst_PrepareMessageData.moc"
