#ifndef CRECEIVERFACTORYIMPLEMENTATION_H
#define CRECEIVERFACTORYIMPLEMENTATION_H

#include "../ServerApplication/src/libs/controllers/IReceiverFactory.h"
#include "../ServerApplication/src/libs/controllers/CReceiver.h"
#include "../ServerApplication/src/libs/testssupport/CReceiverMock.h"

class CReceiverFactoryImplementation : public IReceiverFactory
{
public:
	 IReceiver* Make(QString aReceiverName);
};

#endif // CRECEIVERFACTORYIMPLEMENTATION_H
