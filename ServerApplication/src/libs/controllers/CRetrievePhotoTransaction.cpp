#include "CRetrievePhotoTransaction.h"

#include <litesql.hpp>

#include <QDebug>
#include <QImage>
#include <QImageReader>

#include "src/libs/dao/CRepository.h"

using server::AndroidPhotosDatabase;
using litesql::Blob;

using namespace litesql;

extern CRepository gRepository;

CRetrievePhotoTransaction::CRetrievePhotoTransaction(int aChecksum) :
    mChecksum(aChecksum) {
}

void CRetrievePhotoTransaction::Execute() {
    server::AndroidPhotosDatabase *mDatabase {gRepository.GetDatabase()};

    Photo vPhoto {litesql::select<Photo>(*mDatabase,
                                         Photo::Checksum == mChecksum).one()
                 };

    RetrieveData(vPhoto);
}

QByteArray CRetrievePhotoTransaction::GetData() const {
    return mData;
}

void CRetrievePhotoTransaction::RetrieveData(Photo aPhoto) {
    Blob vBlob {aPhoto.data.value()};

    if (vBlob.isNull()) {
        qDebug() << "Obiektu o podanej sumie kontrolnej nie ma w bazie";

        return;
    }

    size_t vBuffSize {aPhoto.datasize.value()};
    u8_t *vBuffer {new u8_t[vBuffSize]};

    vBlob.getData(vBuffer, vBuffSize);
    mData = QByteArray(reinterpret_cast<char *>(vBuffer), vBuffSize);
}
