#include "CCheckSumList.h"

CChecksumList gChecksumList;

CChecksumList::CChecksumList() {
		// sztucznie wypełniona narazie
        mChecksumList.append(183);
}

void CChecksumList::AddFileChecksum(int aChecksum) {
        mChecksumList.append(aChecksum);
}

void CChecksumList::PopulateChecksumFromDB() {
		/// @todo
}
bool CChecksumList::CheckFileChecksum(int aCheckSum) {
        for (QList<int>::iterator vIter = mChecksumList.begin();
                        vIter != mChecksumList.end(); ++vIter) {
                if (aChecksum == *vIter) {
						return true;
				}
		}

		return false;
}
