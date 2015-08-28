#ifndef CADDTODBTRANSACTION_H
#define CADDTODBTRANSACTION_H

#include "libs/controllers/CTransaction.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"

class CAddToDBTransaction : public CTransaction {
	public:
		CAddToDBTransaction();
		void Execute();

private:
		int mChecksum;
};

#endif // CADDTODBTRANSACTION_H
