#include "CRepository.h"

#include <stdexcept>

#include <QDebug>

CRepository gRepository;

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

  //   if (modelKlienci) {
  //     modelKlienci->odswiez();
  //   }

  //   ModelRejestr *modelRejestr = dynamic_cast<ModelRejestr *>(modelAbstrakcyjny);

  //   if (modelRejestr) {
  //     modelRejestr->odswiez();
  //   }
}

server::database *CRepository::GetDatabase() {//const
  return mDatabase;
}

void CRepository::Connect() {
  try {
    mDatabase = new server::database(driver.toStdString(),
                                     connectionString.toStdString());
    PopulateDatabase();
    odswiezWszystko();

    lastConnectionError = false;
  } catch (std::exception e) {

    lastConnectionError = true;
    bazaDanych = nullptr;
  }
}

void CRepository::PopulateDatabase() {
  if (bazaDanych->needsUpgrade()) {
    bazaDanych->upgrade();
  }
}

void CRepository::Disconnect() {
  delete mDatabase;
  mDatabase = 0;
}

