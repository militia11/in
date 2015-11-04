#ifndef CRECEIVERFACTORYIMPLEMENTATION_H
#define CRECEIVERFACTORYIMPLEMENTATION_H

#include "../ServerApplication/src/libs/controllers/IReceiverFactory.h"
#include "../ServerApplication/src/libs/controllers/CReceiver.h"
#include "../ServerApplication/src/libs/controllers/CReceiverMock.h"

/**
 * @brief The CReceiverFactoryImplementation class is factory of
 *        CReceiver object
 */
class CReceiverFactoryImplementation : public IReceiverFactory {
  public:
    /**
     * @brief Make
     * @return CReceiver object
     */
    IReceiver *Make();//QString aReceiverName
};

#endif // CRECEIVERFACTORYIMPLEMENTATION_H
