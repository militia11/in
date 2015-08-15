#include <QString>
#include <QtTest>

class TestConnectionDB : public QObject
{
	Q_OBJECT

public:
	TestConnectionDB();

private Q_SLOTS:
	void testCase();
};

TestConnectionDB::TestConnectionDB()
{
}

void TestConnectionDB::testCase()
{
	QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestConnectionDB)

#include "tst_TestConnectionDB.moc"
