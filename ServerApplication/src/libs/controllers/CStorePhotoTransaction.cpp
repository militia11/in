#include "CStorePhotoTransaction.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"

#include "libs/dao/CRepository.h"

#include <QImageWriter>
#include <QDebug>

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
    server::AndroidPhotosDatabase *mDatabase  = gRepository.GetDatabase();

    Photo *vPhoto = new Photo(*mDatabase);

    SetAtributtesAddToDB(vPhoto);

    vPhoto->update();

    delete vPhoto;
    //	model->odswiez();
}

void CStorePhotoTransaction::SetAtributtesAddToDB(server::Photo *aPhoto) {
    aPhoto->checksum = mChecksum;
    aPhoto->datasize = mDataSize;

    const char *vDataChar = mData.constData();
    Blob vDataIn(vDataChar, mDataSize);
    aPhoto->data = vDataIn;
}