#ifndef IRECEIVERFACTORY_H
#define IRECEIVERFACTORY_H

#include "../ServerApplication/src/libs/controllers/IReceiver.h"

/**
 * @brief IReceiverFactory is a IReceiverFactory factory class interface
 */
class IReceiverFactory {
	public:
		/**
		 * @brief Make creates Receiver object
		 *
		 * @param aReceiverName specify what kind of receiver we want
		 *        to create CReceiver or CReceiverMock for test
		 * @return Receiver object: CReceiver or CReceiverMock
		 */
		virtual IReceiver *Make() = 0;//QString aReceiverName
};

#endif // IRECEIVERFACTORY_H
