#include <inttypes.h> //uint_t* and int_t* types

#include <QImage>
#include <QImageReader>
#include <QImageWriter>
#include <QString>
#include <QtTest>

#include "libs/controllers/CRetrievePhotoTransaction.h"
#include "libs/controllers/CStorePhotoTransaction.h"
#include "libs/dao/androidphotosdatabase.hpp"
#include "libs/dao/CRepository.h"

extern CRepository gRepository;

class StorePhoto : public QObject {
		Q_OBJECT

	public:
		uint8_t	CalculateFileDataChecksum(QByteArray aData);

	private Q_SLOTS:
		void TestStorePhoto();
};

void StorePhoto::TestStorePhoto() {
		gRepository.SetSettings("sqlite3", "database=:memory:");
		//gRepository.SetSettings("mysql", "host=;user=mmichniewski;password=Militia69;database=ap");
		gRepository.Connect();
		gRepository.PopulateDatabase();

		Q_INIT_RESOURCE(resources);

		QImage vImage = QImage (":/sample_photo.jpeg", "JPEG");

		// add image
		QBuffer vBuffer;

		QImageWriter vWriter(&vBuffer, "JPEG");
		vWriter.write(vImage);

		QByteArray vData = vBuffer.data();

		CStorePhotoTransaction vStoreTransaction(vData, vData.size(), 176);
		vStoreTransaction.Execute();

		server::AndroidPhotosDatabase *vDatabase = gRepository.GetDatabase();

		CRetrievePhotoTransaction vRetrieveTransaction(176);
		vRetrieveTransaction.Execute();
		QByteArray vRetrieveData =  vRetrieveTransaction.GetData();

		// convert array of bytes to image
		QBuffer vBuffer2(&vRetrieveData);
		vBuffer2.open( QIODevice::ReadOnly );
		QImageReader vReader(&vBuffer2, "JPEG");
		QImage vImage2 = vReader.read();

		u_int8_t vChecksumImage = CalculateFileDataChecksum(vData);
		u_int8_t vChecksumImage2 = CalculateFileDataChecksum(vRetrieveData);

		QCOMPARE(vImage.size(), vImage2.size());
		QCOMPARE(vImage.format(), vImage2.format());
		QCOMPARE(vChecksumImage, vChecksumImage2);
		QCOMPARE(vData, vRetrieveData);

		//QVERIFY(vImage2.operator==(vImage));  // porównanie qimage  w tym przypadku różne
		// pixel compare  4281016857 != 4281016597
}

uint8_t StorePhoto::CalculateFileDataChecksum(QByteArray aData) {
		uint8_t vSum = 0;

		for (int i = 0; i < aData.length(); ++i) {
				vSum += aData[i];
		}

		return vSum;
}


QTEST_APPLESS_MAIN(StorePhoto)

#include "tst_StorePhoto.moc"
