#include "CChecksumList.h"

#include <QBuffer>
#include <QImageWriter>

#include "CRepository.h"

extern CRepository gRepository;

CChecksumList::CChecksumList() {
		CalculatePhotosChecksums();
}

void CChecksumList::CalculatePhotosChecksums() {

}

void CChecksumList::Clear() {
		mChecksumList.clear();
}

QByteArray CChecksumList::ConvertImageToByteArray(QImage aImage) {
		QBuffer vBuffer;

		QImageWriter vWriter(&vBuffer, "JPG");
		vWriter.write(aImage);  // unikniecie vWriter.write(*(*vIterator));
		return vBuffer.data();
}

uint16_t CChecksumList::CalculateFileDataChecksum(QByteArray aData) {
		uint16_t vChecksum = 0;

		for (int i = 0; i < aData.length(); ++i) {
				vChecksum += aData[i];
		}

		return vChecksum;
}
