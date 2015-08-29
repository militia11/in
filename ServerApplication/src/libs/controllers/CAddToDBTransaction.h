#ifndef CADDTODBTRANSACTION_H
#define CADDTODBTRANSACTION_H

#include "libs/controllers/CTransaction.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"
#include <QBuffer>

class CAddToDBTransaction : public CTransaction {
	public:
		CAddToDBTransaction(QByteArray aData, int aChecksum);
		void Execute();

private:
		QByteArray mData;
		int mChecksum;
};

#endif // CADDTODBTRANSACTION_H
