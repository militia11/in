#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include "libs/controllers/CSettings.h"

class CSettings;
class CRepository {
	public:
		/**
		 * @brief CRepository constructor.
		 */
		CRepository();

		void SetSettings(const QString &driver, const QString &connectionString);

		void Connect();
		void PopulateDatabase();

	private:
		QString driver;
		QString connectionString;
};

#endif // CREPOSITORY_H
