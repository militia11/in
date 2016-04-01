#include "CStorePhotoTransaction.h"

#include <litesql.hpp>

#include "src/libs/dao/androidphotosdatabase.hpp"
#include "src/libs/dao/CRepository.h"

#include <QImageWriter>

using server::AndroidPhotosDatabase;
using litesql::Blob;

extern CRepository gRepository;

CStorePhotoTransaction::CStorePhotoTransaction(QByteArray aData, int aDataSize,
        int aChecksum) :
    mData(aData),
    mDataSize(aDataSize),
    mChecksum(aChecksum) {
}

void CStorePhotoTransaction::Execute() {
		server::AndroidPhotosDatabase *mDatabase {gRepository.GetDatabase()};

		Photo *vPhoto {new Photo(*mDatabase)};
        SetAtributtesToPhoto(vPhoto);
		vPhoto->update();
		delete vPhoto;

		CChecksumList *vChecksumList {gRepository.GetChecksumList()};
		vChecksumList->AddFileChecksum(mChecksum);
}

void CStorePhotoTransaction::SetAtributtesToPhoto(server::Photo *aPhoto) {
    aPhoto->checksum = mChecksum;
    aPhoto->datasize = mDataSize;

    const char *vDataChar = mData.constData();
    Blob vDataIn(vDataChar, mDataSize);
    aPhoto->data = vDataIn;
}
