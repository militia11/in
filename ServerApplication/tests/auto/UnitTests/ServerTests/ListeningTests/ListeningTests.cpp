#include <QString>
#include <QtTest>

#include "../ServerApplication/src/libs/controllers/CServer.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMockFactory.h"

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
	CReceiverMockFactory *vMockFactory = new CReceiverMockFactory;
	CServer vServer(vMockFactory);
	// dac to do testu na tworzenie ??? tylko jak jak to w incoming

	IReceiver *r = vServer.GetReceiver();
	CReceiverMock *m = dynamic_cast<CReceiverMock *>(r);
	QVERIFY(m);

	vServer.IncomingConnection();
	qDebug() << m->GetLog();

}

QTEST_APPLESS_MAIN(ListeningTests)

#include "ListeningTests.moc"
