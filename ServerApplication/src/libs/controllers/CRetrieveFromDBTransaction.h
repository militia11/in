#ifndef CRETRIEVEFROMDBTRANSACTION_H
#define CRETRIEVEFROMDBTRANSACTION_H

#include"libs/controllers/CTransaction.h"
#include <QByteArray>

class CRetrieveFromDBTransaction : CTransaction {
	public:
		CRetrieveFromDBTransaction(int aChecksum);
		void Execute();
		QByteArray getData() const ;

	private:
		int mChecksum;
		QByteArray mData;
};

#endif // CRETRIEVEFROMDBTRANSACTION_H
