#include "CCheckSumList.h"

CCheckSumList gCheckSumList;

CCheckSumList::CCheckSumList() {
		// sztucznie wypełniona narazie
		mCheckSumList.append(183);
}

void CCheckSumList::AddFileCheckSum(int aCheckSum) {
		mCheckSumList.append(aCheckSum);
}

void CCheckSumList::PopulateCheckSumFromDB() {
		/// @todo
}
bool CCheckSumList::CheckFileCheckSum(int aCheckSum) {
		for (QList<int>::iterator vIter = mCheckSumList.begin();
						vIter != mCheckSumList.end(); ++vIter) {
				if (aCheckSum == *vIter) {
						return true;
				}
		}

		return false;
}
