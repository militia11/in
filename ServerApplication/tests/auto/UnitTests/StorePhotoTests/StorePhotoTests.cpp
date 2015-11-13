#include <inttypes.h> //uint_t* and int_t* types

#include <QImage>
#include <QImageReader>
#include <QImageWriter>
#include <QString>
#include <QtTest>

#include "src/libs/controllers/CRetrievePhotoTransaction.h"
#include "src/libs/controllers/CStorePhotoTransaction.h"
#include "src/libs/dao/CRepository.h"

extern CRepository gRepository;

/**
 * @brief StorePhoto class is test to store and retrieve photo in server.
 */
class StorePhotoTests : public QObject {
    Q_OBJECT

  public:
		uint16_t CalculateFileDataChecksumHelper(QByteArray aData);

  private Q_SLOTS:
		void TestStorePhoto();
};

void StorePhotoTests::TestStorePhoto() {
			gRepository.SetSettings("sqlite3",
                            "database=:memory:"); // dzięki temu, że w pamięci testy można w jenkinsie
    gRepository.Connect();
    gRepository.PopulateDatabase();

    Q_INIT_RESOURCE(server_resources);  // Use resources from diffrent project

		QImage vAddedImage {QImage(":/sample_photo.jpg", "JPG")};

    // Part adding image
    QBuffer vBufferToStoreData;

    QImageWriter vWriter(&vBufferToStoreData, "JPG");
    vWriter.write(vAddedImage);

    QByteArray vAddedData = vBufferToStoreData.data();
		int16_t vChecksumAddImage = CalculateFileDataChecksumHelper(vAddedData);

    CStorePhotoTransaction vStoreTransaction(
        vAddedData, vAddedData.size(), vChecksumAddImage);
    vStoreTransaction.Execute();

    CRetrievePhotoTransaction vRetrieveTransaction(vChecksumAddImage);
    vRetrieveTransaction.Execute();

    QByteArray vRetrievedData = vRetrieveTransaction.GetData();

    QCOMPARE(vAddedData, vRetrievedData);

    // Convert array of bytes to image
    QBuffer vBufferRetrieveData(&vRetrievedData);
    vBufferRetrieveData.open(QIODevice::ReadOnly);

    QImageReader vReader(&vBufferRetrieveData, "JPG");
    QImage vRetrievedImage = vReader.read();

    QCOMPARE(vAddedImage.size(), vRetrievedImage.size());
    QCOMPARE(vAddedImage.format(), vRetrievedImage.format());

    int16_t vChecksumRetrievedImage =
				CalculateFileDataChecksumHelper(vRetrievedData);

    QCOMPARE(vChecksumAddImage, vChecksumRetrievedImage);

    // QVERIFY(vImage2.operator==(vImage));  // porównanie qimage  w tym przypadku różne
    // Pixel compare: różne 4281016857 != 4281016597

}

uint16_t StorePhotoTests::CalculateFileDataChecksumHelper(QByteArray aData) {
    uint16_t vChecksum = 0;

    for (int i = 0; i < aData.length(); ++i) {
        vChecksum += aData[i];
    }

    return vChecksum;
}

QTEST_APPLESS_MAIN(StorePhotoTests)

#include "StorePhotoTests.moc"
