#include "CRepository.h"

#include <QDebug>
#include <QDir>
#include <QStandardPaths>

CRepository gRepository;

CRepository::CRepository() {
}

CRepository::~CRepository() {
}

void CRepository::PopulateRepository() {
  QStringList vPicturesLocation = QStandardPaths::standardLocations(
									QStandardPaths::PicturesLocation);
  QString vPath = vPicturesLocation.at(0);
  QDir vDir(vPath);
  QStringList vAllFiles = vDir.entryList(QDir::Files);

  foreach (QString vLocation, vAllFiles) {
	QString vValidPath = vPath + "/";
	vValidPath += vLocation;
	mImagesPaths.append(vValidPath);
	mImagesNames.append(vLocation);
  }
}

QStringList CRepository::GetImagesPaths() {
	return mImagesPaths;
}

QStringList CRepository::GetImagesNames() {
	return mImagesNames;
}

QString CRepository::GetImagePath(int aNumber)
{
	return mImagesPaths[aNumber];
}
