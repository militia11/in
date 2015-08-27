#ifndef CCHECKSUMLIST_H
#define CCHECKSUMLIST_H

#include <QList>

class CCheckSumList {
	public:
		CCheckSumList();
		/**
		 * @brief AddFileCheckSum add new file data checksum
		 * to checksum list.
		 * @param aCheckSum is new checksum value.
		 */
		void AddFileCheckSum(int aCheckSum);

		/**
		 * @brief PopulateCheckSumFromDB function add checksum file list
		 * of actually server files.
		 */
		void PopulateCheckSumFromDB();

		bool CheckFileCheckSum(int aCheckSum);

	private:
		QList<int> mCheckSumList;
};

#endif // CCHECKSUMLIST_H
