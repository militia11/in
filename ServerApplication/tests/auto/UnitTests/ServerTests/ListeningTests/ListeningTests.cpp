#include <QString>
#include <QtTest>

#include "../ClientApplication/src/libs/controllers/CClientMock.h"
#include "../ServerApplication/src/libs/controllers/CServer.h"

class ListeningTests : public QObject {
    Q_OBJECT

  public:
    ListeningTests();

  private Q_SLOTS:
		void TestStopListening();
};

ListeningTests::ListeningTests() {
}

void ListeningTests::TestStopListening() {
CServer se;
CClientMock cm;
}

QTEST_APPLESS_MAIN(ListeningTests)

#include "ListeningTests.moc"
