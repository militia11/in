#include <QString>
#include <QtTest>

class AddChecksumTests : public QObject
{
	Q_OBJECT

public:
	AddChecksumTests();

private Q_SLOTS:
	void TestAddChecksum();
};

AddChecksumTests::AddChecksumTests()
{
}

void AddChecksumTests::TestAddChecksum()
{
	QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(AddChecksumTests)

#include "AddChecksumTests.moc"
