#include "CReceiverMockFactory.h"
#include "tests/auto/UnitTests/testlibs/CReceiverMock.h"

IReceiver *CReceiverMockFactory::Make() {
    return new CReceiverMock();
}
