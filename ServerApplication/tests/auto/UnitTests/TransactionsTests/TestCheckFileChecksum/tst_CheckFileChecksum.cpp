#include <inttypes.h> //uint_t* and int_t* types

#include <QImage>
#include <QImageWriter>
#include <QString>
#include <QtTest>

#include "libs/controllers/CRetrievePhotoTransaction.h"
#include "libs/controllers/CStorePhotoTransaction.h"
#include "libs/dao/CRepository.h"

extern CRepository gRepository;

class CheckFileChecksum : public QObject {
		Q_OBJECT

	public:
		CheckFileChecksum();
		uint16_t    CalculateFileDataChecksum(QByteArray aData);

	private Q_SLOTS:
		void TestCheckFileChecksumTest();
};

CheckFileChecksum::CheckFileChecksum() {
}

void CheckFileChecksum::TestCheckFileChecksumTest() {
		gRepository.SetSettings("sqlite3",
														"database=:memory:"); // dzięki temu, że w pamięci testy można w jenkinsie
		gRepository.Connect();
		gRepository.PopulateDatabase();

		Q_INIT_RESOURCE(server_resources);  // Use resources from diffrent project

		QImage vAddedImage = QImage(":/sample_photo.jpg", "JPG");

		// Part adding image
		QBuffer vBufferToStoreData;

		QImageWriter vWriter(&vBufferToStoreData, "JPG");
		vWriter.write(vAddedImage);

		QByteArray vAddedData = vBufferToStoreData.data();
		int16_t vChecksumAddImage = CalculateFileDataChecksum(vAddedData);

		CStorePhotoTransaction vStoreTransaction(
				vAddedData, vAddedData.size(), vChecksumAddImage);
		vStoreTransaction.Execute();

		CChecksumList *vChecksumList = gRepository.GetChecksumList();

		QVERIFY(vChecksumList->CheckFileChecksum(vChecksumAddImage));
}

uint16_t CheckFileChecksum::CalculateFileDataChecksum(QByteArray aData) {
		uint16_t vChecksum = 0;

		for (int i = 0; i < aData.length(); ++i) {
				vChecksum += aData[i];
		}

		return vChecksum;
}


QTEST_APPLESS_MAIN(CheckFileChecksum)

#include "tst_CheckFileChecksum.moc"
