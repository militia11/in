#include "CChecksumList.h"

#include "src/libs/dao/CRepository.h"

#include <litesql.hpp>

#include <vector>
#include <QDebug>

#include "src/libs/dao/androidphotosdatabase.hpp"

using server::AndroidPhotosDatabase;
using server::Photo;

extern CRepository gRepository;

using namespace litesql;

CChecksumList::CChecksumList() {
  ReceiveChecksumsFromDB();
}

void CChecksumList::AddFileChecksum(int16_t aChecksum) {
  mChecksumList.append(aChecksum);
}

void CChecksumList::ReceiveChecksumsFromDB() {
  server::AndroidPhotosDatabase *vDatabase  = gRepository.GetDatabase();

  if (vDatabase) {
	std::vector<Photo> vPhotosDatabase;

	vPhotosDatabase = select<Photo>(*vDatabase).all();

	for (std::vector<Photo>::iterator vIterator = vPhotosDatabase.begin();
		 vIterator != vPhotosDatabase.end(); ++vIterator) {
	  mChecksumList.append((*vIterator).checksum.value());
	}
  }
}

bool CChecksumList::CheckFileChecksum(uint16_t aChecksum) {
  for (int vChecksum : mChecksumList) {
	if (aChecksum == vChecksum) {
	  return true;
	}
  }

  return false;
}

int CChecksumList::GetChecksumsCount() const {
  return mChecksumList.length();//count();
}

int CChecksumList::GetChecksum(int aPosition) const {
  return mChecksumList[aPosition];
}

//void CChecksumList::UpdateChecksumList() {
//mChecksumList.clear();
//ReceiveChecksumsFromDB();
//}

void CChecksumList::Clear() {
  mChecksumList.clear();
}
