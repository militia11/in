#include <inttypes.h> //uint_t* and int_t* types

#include <QImage>
#include <QImageReader>
#include <QImageWriter>
#include <QString>
#include <QtTest>

#include "libs/controllers/CRetrievePhotoTransaction.h"
#include "libs/controllers/CStorePhotoTransaction.h"
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
		gRepository.SetSettings("sqlite3", "database=:memory:"); // dzięki temu, że w pamięci testy można w jenkinsie
		gRepository.Connect();
		gRepository.PopulateDatabase();

		Q_INIT_RESOURCE(resources);

		QImage vAddedImage = QImage (":/sample_photo.jpeg", "JPEG");

		// Add image
		QBuffer vBuffer;

		QImageWriter vWriter(&vBuffer, "JPEG");
		vWriter.write(vAddedImage);

		QByteArray vAddedData = vBuffer.data();
		u_int8_t vChecksumAddImage = CalculateFileDataChecksum(vAddedData);

		CStorePhotoTransaction vStoreTransaction(
				vAddedData, vAddedData.size(), vChecksumAddImage);
		vStoreTransaction.Execute();

		CRetrievePhotoTransaction vRetrieveTransaction(vChecksumAddImage);
		vRetrieveTransaction.Execute();

		QByteArray vRetrievedData =  vRetrieveTransaction.GetData();

		QCOMPARE(vAddedData, vRetrievedData);

		// Convert array of bytes to image
		QBuffer vBufferRetrieveData(&vRetrievedData);
		vBufferRetrieveData.open(QIODevice::ReadOnly);

		QImageReader vReader(&vBufferRetrieveData, "JPEG");
		QImage vRetrievedImage = vReader.read();

		QCOMPARE(vAddedImage.size(), vRetrievedImage.size());
		QCOMPARE(vAddedImage.format(), vRetrievedImage.format());

		u_int8_t vChecksumRetrievedImage = CalculateFileDataChecksum(vRetrievedData);

		QCOMPARE(vChecksumAddImage, vChecksumRetrievedImage);

		//QVERIFY(vImage2.operator==(vImage));  // porównanie qimage  w tym przypadku różne
		// pixel compare: różne 4281016857 != 4281016597
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
