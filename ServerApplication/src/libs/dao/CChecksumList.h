#ifndef CCHECKSUMLIST_H
#define CCHECKSUMLIST_H

#include <QList>

/**
 * @brief The CChecksumList class represents list of file checksum.
 */
class CChecksumList {
  public:
    /**
     * @brief CChecksumList constructor
     */
    CChecksumList();

    /**
     * @brief AddFileChecksum add new file data checksum
     *				to checksum list
     *
     * @param aChecksum is new checksum value
     */
    void AddFileChecksum(int16_t aChecksum);

    /**
     * @brief PopulateChecksumFromDB function add checksum file list
     *				of actually server files
     */
    void ReceiveChecksumsFromDB();

    /**
     * @brief CheckFileCheckSum compare checksum in parameter to
     *				checksums in server which we import to list in
     *				class CCheckSumList.
     *
     * @param aCheckSum is checksum we compare to
     *				checksum from server.
     *
     * @return True if checksum is the same in another in server
     */
    bool CheckFileChecksum(uint16_t aChecksum);

    /**
     * @brief Get checksums count
     *
     * @return Checksums count
     */
    int GetChecksumsCount() const;

    /**
      * @brief Get checksum
      *
      * @param aPosition Position
      * @return Checksum value
      */
     int GetChecksum(int aPosition) const;

    /**
     * @brief UpdateChecksumList update list of checksums
     */
    //void UpdateChecksumList();

    /**
     * @brief Clear function is a facade for clear function in
     *				Qlist class.
     */
    void Clear();

  private:
    /**
     * @brief mChecksumList is list of checksums
     */
        QList<uint16_t> mChecksumList;
};

#endif // CCHECKSUMLIST_H
