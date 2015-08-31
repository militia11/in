#include "CRetrieveFromDBTransaction.h"

#include <litesql.hpp>

#include "libs/dao/CRepository.h"

#include <QImageReader>
#include <QImage>
#include <QDebug>

using server::AndroidPhotosDatabase;
using litesql::Blob;

using namespace litesql;

extern CRepository gRepository;

CRetrieveFromDBTransaction::CRetrieveFromDBTransaction(int aChecksum) :
  mChecksum(aChecksum) {
}

void CRetrieveFromDBTransaction::Execute() {
  server::AndroidPhotosDatabase *mDatabase  = gRepository.GetDatabase();

  Photo vPhoto = litesql::select<Photo>(*mDatabase,
                                        Photo::Checksum == mChecksum).one();

  RetrieveData(vPhoto);
}

QByteArray CRetrieveFromDBTransaction::getData() const {
  return mData;
}

void CRetrieveFromDBTransaction::RetrieveData(Photo aPhoto) {
  Blob vBlob = aPhoto.data.value();

  if (vBlob.isNull()) {
    qDebug() << "Obiekt o podanej sumie kontrolnej nie istnieje";
  }

  int vBuffSize = aPhoto.datasize.value(); // 25002;
  u8_t *vBuffer = new u8_t[vBuffSize];

  vBlob.getData(vBuffer, vBuffSize);
  mData = QByteArray(reinterpret_cast<char *>(vBuffer), vBuffSize);
}
