#include <assert.h>
#include <QString>
#include <QtTest>

#include "libs/controllers/CRetrievePhotoTransaction.h"
#include "libs/controllers/CStorePhotoTransaction.h"
#include "libs/dao/androidphotosdatabase.hpp"
#include "libs/dao/CRepository.h"

extern CRepository gRepository;

class RetrievePhoto : public QObject
{
	Q_OBJECT

public:
	RetrievePhoto();

private Q_SLOTS:
	void TestRetrievePhoto();
};

RetrievePhoto::RetrievePhoto()
{
	// image conv and add

	// potem retrieve
/*
	CRetrieveFromDBTransaction vRetrieveTransaction(221);
	vRetrieveTransaction.Execute();
	QByteArray vRetrieveData =  vRetrieveTransaction.GetData();

	// porównać bytesSetAtributtesAddToDB
	// zrobić obrazek zobaczyć czy taki sam ? nie lepiej >> porównać QImage <<

 //tą zerżniętą przerobić co się da
	// zmienić nazwy transakcji na CAddPhotoToDBTransaction i pobierzPhotoFromDBTransaction

	QByteArray aData, int aDataSize,
						 int aChecksum;

	////////////////////////
#include "libs/dao/androidphotosdatabase.hpp"
#include <litesql.hpp>
#include <QImageWriter>
#include <QDebug>

using server::AndroidPhotosDatabase;
using litesql::Blob;*/
	//////////////////////////
}

void RetrievePhoto::TestRetrievePhoto()
{
	QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(RetrievePhoto)

#include "tst_RetrievePhoto.moc"
