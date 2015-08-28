#include "CRepository.h"

#include <stdexcept>

#include <QDebug>

CRepository gRepository;

using server::AndroidPhotosDatabase;
//Model gModel;

CRepository::CRepository()   { //: mDatabase(0)

  mLastConnectionError = false;
}

CRepository::~CRepository() {
  //delete model;
}

void CRepository::SetSettings(const QString &aDriver,
                              const QString &aConnectionString) {
  this->mDriver = aDriver;
  this->mConnectionString = aConnectionString;
}

void CRepository::Refresh() { //QString nazwa jak wiele
  //  QAbstractTableModel *modelAbstrakcyjny = archiwum.pobierzModel(nazwa);

  //   ModelPsy *modelPsy = dynamic_cast<ModelPsy *>(modelAbstrakcyjny);

  //   if (modelPsy) {
  //     modelPsy->odswiez();
  //   }

  //   ModelKlienci *modelKlienci = dynamic_cast<ModelKlienci *>(modelAbstrakcyjny);
}

AndroidPhotosDatabase *CRepository::GetDatabase() { //const //wyproboj
  return mDatabase;
}

void CRepository::Connect() {
  try {
		mDatabase = new server::AndroidPhotosDatabase(mDriver.toStdString(),
																		 mConnectionString.toStdString());
    PopulateDatabase();
    Refresh();

    mLastConnectionError = false;
  } catch (std::exception vException) {

    mLastConnectionError = true;
    mDatabase = nullptr;
  }
}

void CRepository::PopulateDatabase() {
  if (mDatabase->needsUpgrade()) {
    mDatabase->upgrade();
  }
}

void CRepository::Disconnect() {
  delete mDatabase;
  mDatabase = 0;
}

