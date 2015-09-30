#ifndef CRETRIEVEFROMDBTRANSACTION_H
#define CRETRIEVEFROMDBTRANSACTION_H

#include"libs/controllers/CTransaction.h"

#include "libs/dao/androidphotosdatabase.hpp"

#include <QByteArray>

using server::Photo;

/**
 * @brief The CRetrieveFromDBTransaction class retrieve blob data
 * from database.
 */
class CRetrieveFromDBTransaction : CTransaction {
  public:
    CRetrieveFromDBTransaction(int aChecksum);

    /**
     * @brief Execute method is call to confirm transaction.
     */
    void Execute();

    /**
     * @brief getData return array of bytes.
     *
     * @return Array of bytes.
     */
    QByteArray getData() const ;

  private:
    /**
     * @brief RetrieveData retrieve data from database.
     *
     * @param aPhoto is Photo data which indicate to correct photo.
     */
    void RetrieveData(Photo aPhoto);

    /**
     * @brief mChecksum is checksum of file.
     */
    int mChecksum;

    /**
     * @brief mData is data of photo file.
     */
    QByteArray mData;
};

#endif // CRETRIEVEFROMDBTRANSACTION_H
