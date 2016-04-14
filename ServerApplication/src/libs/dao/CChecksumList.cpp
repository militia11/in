#include "CChecksumList.h"

#include <litesql.hpp>

#include <vector>
#include <QDebug>

#include "src/libs/dao/androidphotosdatabase.hpp"
#include "src/libs/dao/CRepository.h"

using server::AndroidPhotosDatabase;
using server::Photo;

extern CRepository gRepository;

using namespace litesql;

CChecksumList::CChecksumList() {
  ReceiveChecksumsFromDB();
}

void CChecksumList::AddFileChecksum(int32_t aChecksum) {
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

bool CChecksumList::CheckFileChecksum(int32_t aChecksum) {
	qDebug() << "achceksum first jest rowne: " <<aChecksum;
  for (int vChecksum : mChecksumList) {
	  qDebug() << "kazda chceksum:" <<vChecksum;
	if (aChecksum == vChecksum) {
		qDebug() << "rowna ta sama: " <<vChecksum;
	  return true;
	}
  }

  return false;
}

int CChecksumList::GetChecksumsCount() const {
  return mChecksumList.length();
}

int CChecksumList::GetChecksum(int aPosition) const {
  return mChecksumList[aPosition];
}

void CChecksumList::Clear() {
  mChecksumList.clear();
}
