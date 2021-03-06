#ifndef CSTOREPHOTOTRANSACTION_H
#define CSTOREPHOTOTRANSACTION_H

#include <litesql.hpp>
#include "src/libs/dao/androidphotosdatabase.hpp"

#include <QBuffer>

#include "src/libs/controllers/CTransaction.h"

using server::Photo;

/**
 * @brief The CStorePhotoTransaction class is transaction which add record
 *        to database
 */
class CStorePhotoTransaction : public CTransaction {
 public:
  explicit CStorePhotoTransaction(QByteArray aData, int aDataSize, int32_t aChecksum);

  /**
   * @brief Store photo into database and update checksum list
   *
   * Execute method is call to confirm transaction
   */
  void Execute();

 private:
  /**
   * @brief SetAtributtesAddToDB set attribures for new document
   *
   * @param aPhoto represents Photo Document stored in
   *        database
   */
  void SetAtributtesToPhoto(server::Photo *aPhoto);

  /**
   * @brief mData is data of photo file
   */
  QByteArray mData;

  /**
   * @brief mDataSize is data size of file
   */
  int mDataSize;

  /**
   * @brief mChecksum is checksum of file
   */
  int32_t mChecksum;
};

#endif // CSTOREPHOTOTRANSACTION_H
