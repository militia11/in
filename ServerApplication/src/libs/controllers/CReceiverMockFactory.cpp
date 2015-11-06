#include "CReceiverMockFactory.h"
#include "src/libs/controllers/CReceiverMock.h"

IReceiver *CReceiverMockFactory::Make() {
    return new CReceiverMock();
}
