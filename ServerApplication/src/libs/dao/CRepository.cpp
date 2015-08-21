#include "CRepository.h"

#include <stdexcept>

#include <QDebug>

CRepository gRepository;

CRepository::CRepository() : mDatabase(0) {
		mLastConnectionError = false;
}

void CRepository::SetSettings(
		const QString &aDriver,
		const QString &aHost,
		const QString &aDatabaseName,
		const QString &aUser,
		const QString &aPassword
) {
		this->mDriver = aDriver;
		this->mHost = aHost;
		this->mDatabaseName = aDatabaseName;
		this->mUser = aUser;
		this->mPassword = aPassword;
}

qx::QxSqlDatabase *CRepository::GetDatabase() {//const
		return mDatabase;
}

void CRepository::Connect() {
		//    /// @todo
		//    try {
		//        //    bazaDanych = new schro::schronisko(driver.toStdString(),
		//        //                                     connectionString.toStdString());
		//        //    wypelnijBazeDanych();
		//        //    odswiezWszystko();

		//        mLastConnectionError = false;
		//    } catch (std::exception aException) {

		//        mLastConnectionError = true;
		//        ///bazaDanych = nullptr;
		//    }
		qx::QxSqlDatabase::clearAllDatabases();
		mDatabase = qx::QxSqlDatabase::getSingleton();

		mLastConnectionError = false;
		mDatabase->setDriverName(driver);
		mDatabase->setHostName(host);
		mDatabase->setDatabaseName(databaseName);
		mDatabase->setUserName(user);
		mDatabase->setPassword(password);

		if (!mDatabase->getDatabase().open()) {
				mDatabase = NULL;
				mLastConnectionError = true;
		}
}

void CRepository::PopulateDatabase() {
		/*
		 * @TODO: Wersjonowanie schematu bazy
		 *
		 * To nie może tak zostać!
		 *
		 *    http://www.qxorm.com/doxygen/html/group___qx_dao.html#gacdaac47549d0e850cf5d6a16315efaab
		 *
		 * Zamiast tego powinno być wersjonowanie bazy danych
		 */
		/*qx::dao::create_table<Pies>();
		qx::dao::create_table<Material>();
		qx::dao::create_table<Wydanie>();*/
		//qx::dao::create_table<Klient>();
}

void CRepository::Disconnect() {
		delete mDatabase;
		mDatabase = 0;
}

