#include <QString>
#include <QtTest>

#include <libs/dao/androidphotosdatabase.hpp>

#include "libs/controllers/CClient.h"

class TestReceiveNewData : public QObject {
    Q_OBJECT

  public:
    TestReceiveNewData();

  private Q_SLOTS:
    void testCase();
};

TestReceiveNewData::TestReceiveNewData() {
}

void TestReceiveNewData::testCase() {
    //	CClient * vClient = new CClient;
    //	const char *vData = ">D02035780D0A";
    /// @todo pomyslec jak newdata nie ma parametru

    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestReceiveNewData)

#include "tst_TestReceiveNewData.moc"
