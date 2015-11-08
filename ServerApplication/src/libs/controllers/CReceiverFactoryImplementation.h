#ifndef CRECEIVERFACTORYIMPLEMENTATION_H
#define CRECEIVERFACTORYIMPLEMENTATION_H

#include "src/libs/controllers/CReceiver.h"
#include "src/libs/controllers/IReceiverFactory.h"


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
		IReceiver *Make();
};

#endif // CRECEIVERFACTORYIMPLEMENTATION_H
