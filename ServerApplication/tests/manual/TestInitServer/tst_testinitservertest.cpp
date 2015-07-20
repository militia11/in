#include <QString>
#include <QtTest>

class TestInitServerTest : public QObject
{
    Q_OBJECT

  public:
    TestInitServerTest();

  private Q_SLOTS:
    void testCase1Init();
};

TestInitServerTest::TestInitServerTest()
{
}

void TestInitServerTest::testCase1Init()
{
  QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestInitServerTest)

#include "tst_testinitservertest.moc"
