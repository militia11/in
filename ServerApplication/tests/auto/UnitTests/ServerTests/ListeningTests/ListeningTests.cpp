#include <QString>
#include <QtTest>

class ListeningTests : public QObject
{
	Q_OBJECT

public:
	ListeningTests();

private Q_SLOTS:
	void TestStopListening();
};

ListeningTests::ListeningTests()
{
}

void ListeningTests::TestStopListening()
{
	QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ListeningTests)

#include "ListeningTests.moc"
