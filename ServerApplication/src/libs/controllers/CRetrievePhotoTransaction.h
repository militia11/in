#ifndef CRETRIEVEPHOTOTRANSACTION_H
#define CRETRIEVEPHOTOTRANSACTION_H

#include "src/libs/controllers/CTransaction.h"

#include <QByteArray>

#include "src/libs/dao/androidphotosdatabase.hpp"

using server::Photo;

/**
 * @brief The CRetrieveFromDBTransaction class retrieve blob data
 *      from database
 */
class CRetrievePhotoTransaction : CTransaction {
 public:
  /**
   * @brief Constructor CRetrieveFromDBTransaction class
   *
   * @param aChecksum Checksum
   */
  explicit CRetrievePhotoTransaction(int aChecksum);

  /**
   * @brief Retrieve photo from database
   *
   * Execute method is call to confirm transaction
   */
  void Execute();

  /**
   * @brief getData return array of bytes
   *
   * @return Array of bytes
   */
  QByteArray GetData() const ;

 private:
  /**
   * @brief RetrieveData retrieve data from database
   *
   * @param aPhoto is Photo data which indicate to correct photo
   */
  void RetrieveData(Photo aPhoto);

  /**
   * @brief mChecksum is checksum of file
   */
  int mChecksum;

  /**
   * @brief mData is data of photo file
   */
  QByteArray mData;
};

#endif // CRETRIEVEPHOTOTRANSACTION_H
