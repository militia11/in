#include <assert.h>
#include <QImage>
#include <QString>
#include <QtTest>

#include "libs/controllers/CStorePhotoTransaction.h"
#include "libs/dao/androidphotosdatabase.hpp"
#include "libs/dao/CRepository.h"

extern CRepository gRepository;

class StorePhoto : public QObject {
		Q_OBJECT

  private Q_SLOTS:
		void TestStorePhoto();
};

void StorePhoto::TestStorePhoto() {
		/*gRepository.SetSettings("sqlite3", "database=:memory:");
		gRepository.Connect();
		gRepository.PopulateDatabase();
		QByteArray aData;
		int aDataSize;
		int aChecksum;
		CStorePhotoTransaction vTransaction(aData, aDataSize, aChecksum);
		vTransaction.Execute();

		server::AndroidPhotosDatabase *vDatabase = gRepository.GetDatabase();
		///
		QImage vImage = QImage ("/home/mmichniewski/b.jpeg", "JPEG");
		ui->mImageLabel->setPixmap(
				QPixmap::fromImage(vImage));
		///
		//	Photo vPhotoFromDB = litesql::select<Photo>(*mDatabase,
		//		Photo::Checksum == mChecksum).one();

		//	Photo *vPtrPohotoFromDB = &vPhotoFromDB;
*/
		//	assert(vPtrPohotoFromDB);
		//	QCOMPARE(vPtrPohotoFromDB.)
		//			ring("Aza"));
		//	QCOMPARE(wskPiesZBazy->rasa.value(), std::string("Doberman"));
		//	QCOMPARE(wskPiesZBazy->usposobienie.value(), Pies::UsposobienieType::Lagodny);
}

QTEST_APPLESS_MAIN(StorePhoto)

#include "tst_StorePhoto.moc"
