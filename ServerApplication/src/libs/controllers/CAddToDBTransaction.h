#ifndef CADDTODBTRANSACTION_H
#define CADDTODBTRANSACTION_H

#include "libs/controllers/CTransaction.h"

#include <litesql.hpp>

#include "libs/dao/androidphotosdatabase.hpp"

#include <QBuffer>

using server::Photo;

/**
 * @brief The CAddToDBTransaction class is transaction which add record
 * to database.
 */
class CAddToDBTransaction : public CTransaction {
  public:
    CAddToDBTransaction(QByteArray aData, int aDataSize, int aChecksum);

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

#endif // CADDTODBTRANSACTION_H
