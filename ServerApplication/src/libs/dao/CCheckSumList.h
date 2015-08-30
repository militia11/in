#ifndef CCHECKSUMLIST_H
#define CCHECKSUMLIST_H

#include <QList>

/**
 * @brief The CChecksumList class represents list of file checksum.
 *
 * @details @todo dopisać
 */
class CChecksumList {
  public:
    /**
     * @brief CChecksumList constructor.
     */
        CChecksumList();
		/**
         * @brief AddFileChecksum add new file data checksum
		 * to checksum list.
         * @param aChecksum is new checksum value.
		 */
        void AddFileChecksum(int aChecksum);

		/**
         * @brief PopulateChecksumFromDB function add checksum file list
		 * of actually server files.
		 */
        void PopulateChecksumFromDB();

    /**
     * @brief CheckFileCheckSum compare checksum in parameter to checksums in server
     * which we import to list in class CCheckSumList.
     * @param aCheckSum is checksum we compare to
     * checksum from server.
     * @return TRUE if checksum is the same in another in server.
     */
		bool CheckFileChecksum(int aCheckSum);

	private:
        QList<int> mChecksumList;
};

#endif // CCHECKSUMLIST_H
