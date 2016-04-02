#include "CRepository.h"

#include <stdexcept>

#include <QDebug>

CRepository gRepository;

using server::AndroidPhotosDatabase;

CRepository::CRepository() : mDatabase(nullptr),
    mChecksumList(nullptr) {
    mLastConnectionError = false;
}

CRepository::~CRepository() {
    Disconnect();

    delete mChecksumList;
    mChecksumList = nullptr;
}

void CRepository::SetSettings(const QString &aDriver,
                              const QString &aConnectionString) {
    this->mDriver = aDriver;
    this->mConnectionString = aConnectionString;
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
        UpdateChecksums();

        mLastConnectionError = false;
    } catch (std::exception &vException) {
        AttendDatabaseConnectionException(vException.what());
    }
}

void CRepository::PopulateDatabase() {
    if (mDatabase->needsUpgrade()) {
        mDatabase->upgrade();
    }
}

void CRepository::Disconnect() {
    delete mDatabase;
		mDatabase = nullptr;
}

void CRepository::AttendDatabaseConnectionException(const char *aException) {
		qDebug() << "Database connection error:" +
						 QString::fromStdString(aException);

		mLastConnectionError = true;
		mDatabase = nullptr;
}

void CRepository::UpdateChecksums() {
    if (mChecksumList) {
        mChecksumList->Clear();
        mChecksumList->ReceiveChecksumsFromDB();
    } else {
        mChecksumList = new CChecksumList;
    }
}

