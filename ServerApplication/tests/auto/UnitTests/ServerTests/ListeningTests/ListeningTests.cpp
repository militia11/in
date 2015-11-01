#include <QString>
#include <QtTest>

#include "src/libs/testssupport/CClientMock.h"
//#include "src/libs/controllers/IServer.h"
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
//CServer *vServer = new CServer;
}

QTEST_APPLESS_MAIN(ListeningTests)

#include "ListeningTests.moc"
