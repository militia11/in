#include "CReceiverFactoryImplementation.h"

IReceiver *CReceiverFactoryImplementation::Make() {//QString aReceiverName
		/*if (aReceiverName == "CReceiver") {
				return new CReceiver();
				} else if(aReceiverName == "CReceiverMock"){
				return new CReceiverMock();
		} else {
				;//throw std::runtime_error();
				///@todo
		}*/

	/// tu zrobic samo stworzenie prawdziwej!!!!!!!!!!!!!!!!!!!!!!!11
	return new CReceiver();
}
