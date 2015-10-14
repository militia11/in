#include <QString>
#include <QtTest>

#include "libs/controllers/CClient.h"

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
    CClient vClient;
    u_int16_t vChecksum = 384;
    QByteArray vResultData = vClient.PrepareMessageData(vChecksum);
    QByteArray vExpectedData(">>384<");

    QCOMPARE(vResultData, vExpectedData);
}

QTEST_APPLESS_MAIN(PrepareMessageData)

#include "tst_PrepareMessageData.moc"
