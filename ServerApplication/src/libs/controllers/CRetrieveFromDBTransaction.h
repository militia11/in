#ifndef CRETRIEVEFROMDBTRANSACTION_H
#define CRETRIEVEFROMDBTRANSACTION_H

#include"libs/controllers/CTransaction.h"

class CRetrieveFromDBTransaction : public CTransaction {
	public:
		CRetrieveFromDBTransaction();
		void Execute();
};

#endif // CRETRIEVEFROMDBTRANSACTION_H
