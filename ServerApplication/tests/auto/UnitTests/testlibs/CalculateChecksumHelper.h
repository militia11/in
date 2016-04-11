#ifndef CALCULATECHECKSUMHELPER_H
#define CALCULATECHECKSUMHELPER_H

#include <inttypes.h> //uint_t* and int_t* types
#include <QByteArray>

/**
 * @brief The CalculateChecksumHelper class is helper for unit test
 *        which need to calculate checksum
 */
class CalculateChecksumHelper {
 public:
  /**
  * @brief CalculateChecksumHelper constructor
  */
  CalculateChecksumHelper();

  /**
   * @brief CalculateFileDataChecksum calculate checksum from data
   *
   * @param aData Data to calculate checksum
   * @return calculate checksum
   */
  static uint16_t CalculateFileDataChecksum(QByteArray aData);
};

#endif // CALCULATECHECKSUMHELPER_H
