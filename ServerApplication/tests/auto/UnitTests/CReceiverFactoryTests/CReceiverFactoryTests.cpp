#include <QString>
#include <QtTest>

//#include "../ServerApplication/src/libs/controllers/CReceiver.h"
//#include "../ServerApplication/src/libs/controllers/CReceiverFactoryImplementation.h"
//#include "../ServerApplication/src/libs/controllers/IReceiver.h"

//#include "../ServerApplication/src/libs/testssupport/CReceiverMock.h"
//#include "../ServerApplication/src/libs/testssupport/CReceiverMock.h"

class CReceiverFactoryTests : public QObject {
	Q_OBJECT
public:
	CReceiverFactoryTests();

private Q_SLOTS:
	void TestCreateReceiver();
	void TestCreateMock();
};

CReceiverFactoryTests::CReceiverFactoryTests()
{
}

void CReceiverFactoryTests::TestCreateReceiver()
{
	//CReceiverFactoryImplementation vFactory;
	//IReceiver *vReceiverInterface = 0;//vFactory.Make("CReceiverMock");
	//QVERIFY(vReceiverInterface);
}

void CReceiverFactoryTests::TestCreateMock()
{

}

QTEST_APPLESS_MAIN(CReceiverFactoryTests)

#include "CReceiverFactoryTests.moc"
