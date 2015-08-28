#ifndef CCHECKSUMLIST_H
#define CCHECKSUMLIST_H

#include <QList>

/**
 * @brief The CCheckSumList class represents list of file checksum.
 *
 * @details @todo dopisać
 */
class CCheckSumList {
  public:
    /**
     * @brief CCheckSumList constructor.
     */
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

    /**
     * @brief CheckFileCheckSum compare checksum in parameter to checksums in server
     * which we import to list in class CCheckSumList.
     * @param aCheckSum is checksum we compare to
     * checksum from server.
     * @return TRUE if checksum is the same in another in server.
     */
		bool CheckFileCheckSum(int aCheckSum);

	private:
		QList<int> mCheckSumList;
};

#endif // CCHECKSUMLIST_H
