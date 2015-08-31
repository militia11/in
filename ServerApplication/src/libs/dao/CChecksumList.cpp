#include "CChecksumList.h"

#include "libs/dao/CRepository.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"

#include <vector>

#include <QDebug>

using server::AndroidPhotosDatabase;
using server::Photo;

extern CRepository gRepository;

using namespace litesql;

CChecksumList::CChecksumList() {
    ReceiveChecksumsFromDB();
}

void CChecksumList::AddFileChecksum(int aChecksum) {
    mChecksumList.append(aChecksum);
}

void CChecksumList::ReceiveChecksumsFromDB() {
    server::AndroidPhotosDatabase *vDatabase  = gRepository.GetDatabase();

    if (vDatabase) {
        std::vector<Photo> vPhotosDatabase;

        vPhotosDatabase = select<Photo>(*vDatabase).all();

        for (std::vector<Photo>::iterator vIt = vPhotosDatabase.begin();
                vIt != vPhotosDatabase.end(); ++vIt) {
            mChecksumList.append((*vIt).checksum.value());
        }
    }
}
bool CChecksumList::CheckFileChecksum(int aChecksum) {
    for (QList<int>::iterator vIter = mChecksumList.begin();
            vIter != mChecksumList.end(); ++vIter) {
        if (aChecksum == *vIter) {
            return true;
        }
    }

    return false;
}

void CChecksumList::Clear() {
    mChecksumList.clear();
}
