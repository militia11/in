#ifndef CADDTODBTRANSACTION_H
#define CADDTODBTRANSACTION_H

#include "libs/controllers/CTransaction.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"
#include <QBuffer>

using server::Photo;

class CAddToDBTransaction : public CTransaction {
	public:
		CAddToDBTransaction(QByteArray aData, int aDataSize, int aChecksum);
		void Execute();

	private:
		void SetAtributtesAddToDB(server::Photo *aPhoto);

		QByteArray mData;
		int mDataSize;
		int mChecksum;
};

#endif // CADDTODBTRANSACTION_H
