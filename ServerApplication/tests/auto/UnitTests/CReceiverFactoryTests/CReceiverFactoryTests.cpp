#include <QString>
#include <QtTest>

#include "../ServerApplication/src/libs/controllers/CReceiver.h"
#include "../ServerApplication/src/libs/controllers/CReceiverFactoryImplementation.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMockFactory.h"
#include "../ServerApplication/src/libs/controllers/IReceiver.h"

class CReceiverFactoryTests : public QObject {
	Q_OBJECT
public:
	CReceiverFactoryTests();

private Q_SLOTS:
  void TestReturnReceiver();
  void TestReturnMockReceiver();
  void TestWrongFactoryReceiver();
  void TTestWrongFactoryMock();
};

CReceiverFactoryTests::CReceiverFactoryTests()
{
}

void CReceiverFactoryTests::TestReturnReceiver()
{
  CReceiverFactoryImplementation vFactory;
  IReceiver *vReceiverInterface = vFactory.Make();
  CReceiver *vReceiver = dynamic_cast<CReceiver *>(vReceiverInterface);
  QVERIFY(vReceiver);
}

void CReceiverFactoryTests::TestReturnMockReceiver()
{
  CReceiverMockFactory vFactory;
  IReceiver *vReceiverInterface = vFactory.Make();
  CReceiverMock *vReceiverMock = dynamic_cast<CReceiverMock *>(vReceiverInterface);
  QVERIFY(vReceiverMock);
}

void CReceiverFactoryTests::TestWrongFactoryReceiver()
{
  CReceiverFactoryImplementation vFactory;
  IReceiver *vReceiverInterface = vFactory.Make();
  CReceiverMock *vReceiverMock = dynamic_cast<CReceiverMock *>(vReceiverInterface);

  QEXPECT_FAIL("", "Wrong Factory", Continue);
  QVERIFY(vReceiverMock);
}

void CReceiverFactoryTests::TTestWrongFactoryMock()
{
  CReceiverMockFactory vFactory;
  IReceiver *vReceiverInterface = vFactory.Make();
  CReceiver *vReceiver = dynamic_cast<CReceiver *>(vReceiverInterface);

  QEXPECT_FAIL("", "Wrong Factory", Continue);
  QVERIFY(vReceiver);
}

QTEST_APPLESS_MAIN(CReceiverFactoryTests)

#include "CReceiverFactoryTests.moc"
