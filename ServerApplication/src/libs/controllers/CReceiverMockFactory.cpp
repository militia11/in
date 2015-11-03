#include "CReceiverMockFactory.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"

IReceiver *CReceiverMockFactory::Make()
{
	return new CReceiverMock();
}
