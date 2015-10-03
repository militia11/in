#ifndef CSTOREPHOTOTRANSACTION_H
#define CSTOREPHOTOTRANSACTION_H

#include "libs/controllers/CTransaction.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"

#include <QBuffer>

using server::Photo;

/**
 * @brief The CStorePhotoTransaction class is transaction which add record
 * to database.
 */
class CStorePhotoTransaction : public CTransaction {
  public:
    CStorePhotoTransaction(QByteArray aData, int aDataSize, int aChecksum);

    /**
     * @brief Execute method is call to confirm transaction.
     */
    void Execute();

  private:
    /**
     * @brief SetAtributtesAddToDB set attribures for new document .
     * @param aPhoto represents Photo Document stored in
     * database.
     */
    void SetAtributtesAddToDB(server::Photo *aPhoto);

    /**
     * @brief mData is data of photo file.
     */
    QByteArray mData;

    /**
     * @brief mDataSize is data size of file.
     */
    int mDataSize;

    /**
     * @brief mChecksum is checksum of file.
     */
    int mChecksum;
};

#endif // CSTOREPHOTOTRANSACTION_H
