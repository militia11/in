#include "CRepository.h"

#include <stdexcept>

#include <QDebug>

CRepository gRepository;

using server::AndroidPhotosDatabase;
//Model gModel;

CRepository::CRepository() : mDatabase(0),
		mChecksumList(0) {
		mLastConnectionError = false;
}

CRepository::~CRepository() {
		Disconnect();
		delete mChecksumList;
		mChecksumList = 0;
		//delete model;
}

void CRepository::SetSettings(const QString &aDriver,
                              const QString &aConnectionString) {
		this->mDriver = aDriver;
		this->mConnectionString = aConnectionString;
}

void CRepository::RefreshModel() { //QString nazwa jak wiele

		//  QAbstractTableModel *modelAbstrakcyjny = archiwum.pobierzModel(nazwa);

		//   ModelPsy *modelPsy = dynamic_cast<ModelPsy *>(modelAbstrakcyjny);

		//   if (modelPsy) {
		//     modelPsy->odswiez();
		//   }

		//   ModelKlienci *modelKlienci = dynamic_cast<ModelKlienci *>(modelAbstrakcyjny);
}

AndroidPhotosDatabase *CRepository::GetDatabase() const { //const //wyproboj
		return mDatabase;
}

CChecksumList *CRepository::GetChecksumList() const {
		return mChecksumList;
}

void CRepository::Connect() {
		try {
				mDatabase = new server::AndroidPhotosDatabase(mDriver.toStdString(),
								mConnectionString.toStdString());
				PopulateDatabase();
				RefreshChecksums();
				RefreshModel(); ///@todo jesli sumy tylko nie bedzie modeli to usunac

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

void CRepository::RefreshChecksums() {
		if (mChecksumList) {
				mChecksumList->Clear();
				mChecksumList->ReceiveChecksumsFromDB();
		} else {
				mChecksumList = new CChecksumList;
		}
}

