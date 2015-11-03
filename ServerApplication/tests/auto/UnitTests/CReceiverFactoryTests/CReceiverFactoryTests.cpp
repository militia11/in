#include <QString>
#include <QtTest>

#include "../ServerApplication/src/libs/controllers/CReceiver.h"
#include "../ServerApplication/src/libs/controllers/CReceiverFactoryImplementation.h"
#include "../ServerApplication/src/libs/controllers/IReceiver.h"

#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"
//#include "../ServerApplication/src/libs/testssupport/CReceiverMock.h"

class CReceiverFactoryTests : public QObject {
	Q_OBJECT
public:
	CReceiverFactoryTests();

private Q_SLOTS:
	void TestCreateReceiver();
	void TestCreateMock();
	void TestWrongParam();
};

CReceiverFactoryTests::CReceiverFactoryTests()
{
}

void CReceiverFactoryTests::TestCreateReceiver()
{
	/*CReceiverFactoryImplementation vFactory;
	IReceiver *vReceiverInterface = vFactory.Make("CReceiver");
	QVERIFY(vReceiverInterface);

	CReceiver *vReceiver = dynamic_cast<CReceiver *>(vReceiverInterface);
	QVERIFY(vReceiver);*/
}

void CReceiverFactoryTests::TestCreateMock()
{/*
	CReceiverFactoryImplementation vFactory;
	IReceiver *vReceiverInterface = vFactory.Make("CReceiverMock");
	QVERIFY(vReceiverInterface);

	CReceiverMock *vReceiverMock = dynamic_cast<CReceiverMock *>(vReceiverInterface);
	QVERIFY(vReceiverMock);*/
}

void CReceiverFactoryTests::TestWrongParam()
{/*
	CReceiverFactoryImplementation vFactory;
	IReceiver *vReceiverInterface = vFactory.Make("wrong param");

	QEXPECT_FAIL("", "Wrong Param", Continue);
	QVERIFY(vReceiverInterface);*/
}

QTEST_APPLESS_MAIN(CReceiverFactoryTests)

#include "CReceiverFactoryTests.moc"
