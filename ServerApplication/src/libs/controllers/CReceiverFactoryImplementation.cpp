#include "CReceiverFactoryImplementation.h"

IReceiver *CReceiverFactoryImplementation::Make() {
    return new CReceiver();
}
