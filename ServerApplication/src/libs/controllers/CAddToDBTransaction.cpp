#include "CAddToDBTransaction.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"

#include "libs/dao/CRepository.h"

#include <QImageWriter>
#include <QDebug>

using server::AndroidPhotosDatabase;
using server::Photo;
using litesql::Blob;

extern CRepository gRepository;

CAddToDBTransaction::CAddToDBTransaction(QByteArray aData, int aDataSize, int aChecksum) :
		mData(aData),
		mDataSize(aDataSize),
		mChecksum(aChecksum) {
}

void CAddToDBTransaction::Execute() {
		server::AndroidPhotosDatabase *mDatabase  = gRepository.GetDatabase();

		Photo vPhoto(*mDatabase);

		vPhoto.checksum = mChecksum;
		vPhoto.datasize = mDataSize;
		const char *vDataChar = mData.constData();
		Blob vDataIn(vDataChar, mDataSize);
		vPhoto.data = vDataIn;

		vPhoto.update();
		//	model->odswiez();
}
