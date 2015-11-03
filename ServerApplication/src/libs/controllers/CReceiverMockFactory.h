#ifndef CRECEIVERMOCKFACTORY_H
#define CRECEIVERMOCKFACTORY_H

#include "../ServerApplication/src/libs/controllers/IReceiverFactory.h"
#include "../ServerApplication/src/libs/controllers/IReceiver.h"

class CReceiverMockFactory : public IReceiverFactory
{
public:
	IReceiver *Make();
};

#endif // CRECEIVERMOCKFACTORY_H
