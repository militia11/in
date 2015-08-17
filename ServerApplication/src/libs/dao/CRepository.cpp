#include "CRepository.h"

CRepository gRepository;

CRepository::CRepository() {

}

void CRepository::SetSettings(const QString &driver,
															const QString &connectionString) {
	this->driver = driver;
	this->connectionString = connectionString;
}

void CRepository::Connect() {
	/// @todo
}

void CRepository::PopulateDatabase()
{

}
