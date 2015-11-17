#include "CalculateChecksumHelper.h"

CalculateChecksumHelper::CalculateChecksumHelper() {
}

uint16_t CalculateChecksumHelper::CalculateFileDataChecksum(QByteArray aData) {
  uint16_t vChecksum {};

  for (auto i = 0; i < aData.length(); ++i) {
    vChecksum += aData[i];
  }

  return vChecksum;
}
