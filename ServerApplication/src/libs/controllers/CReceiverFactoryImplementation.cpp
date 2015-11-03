#include "CReceiverFactoryImplementation.h"


IReceiver *CReceiverFactoryImplementation::Make(QString aReceiverName)
{return 0;

	if(aReceiverName == "CReceiver") {
		return new CReceiver();
	} else if(aReceiverName == "CReceiverMock"){
		return new CReceiverMock();
	} else {
		;//throw std::runtime_error();
		///@todo
	}
}
