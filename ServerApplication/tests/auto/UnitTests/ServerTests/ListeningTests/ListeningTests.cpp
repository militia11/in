#include <QString>
#include <QtTest>

#include "../ServerApplication/src/libs/controllers/CServer.h"
#include "../ServerApplication/src/libs/testssupport/CReceiverMock.h"

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
  CServer vSe;
  CReceiverMock *rm = new CReceiverMock;
}

QTEST_APPLESS_MAIN(ListeningTests)

#include "ListeningTests.moc"
