#ifndef CRETRIEVEFROMDBTRANSACTION_H
#define CRETRIEVEFROMDBTRANSACTION_H

#include"libs/controllers/CTransaction.h"

#include "libs/dao/androidphotosdatabase.hpp"

#include <QByteArray>

using server::Photo;

/**
 * @brief The CRetrieveFromDBTransaction class retrieve blob data
 * from database.
 */
class CRetrieveFromDBTransaction : CTransaction {
	public:
		CRetrieveFromDBTransaction(int aChecksum);

    /**
     * @brief Execute method is call to confirm transaction.
     */
		void Execute();

    /**
     * @brief getData
     * @return array of bytes.
     */
		QByteArray getData() const ;

    private:
       void RetrieveData(Photo aPhoto);

		int mChecksum;
        QByteArray mData;
};

#endif // CRETRIEVEFROMDBTRANSACTION_H
