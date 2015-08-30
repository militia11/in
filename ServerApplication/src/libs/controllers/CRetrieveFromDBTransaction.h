#ifndef CRETRIEVEFROMDBTRANSACTION_H
#define CRETRIEVEFROMDBTRANSACTION_H

#include"libs/controllers/CTransaction.h"

#include "libs/dao/androidphotosdatabase.hpp"

#include <QByteArray>

using server::Photo;

class CRetrieveFromDBTransaction : CTransaction {
	public:
		CRetrieveFromDBTransaction(int aChecksum);
		void Execute();
		QByteArray getData() const ;

    private:
       void RetrieveData(Photo aPhoto);

		int mChecksum;
        QByteArray mData;
};

#endif // CRETRIEVEFROMDBTRANSACTION_H
