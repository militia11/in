#ifndef CReceiverWRAPPER_H
#define CReceiverWRAPPER_H

#include "src/libs/controllers/CReceiver.h"

/**
 * @brief Wrapper for CReceiver class
 *
 * Used to access protected variables in tests
 */
class CReceiverWrapper : public CReceiver {
 public:
  char *ForTestGetMessageFileChecksum();
  int ForTestGetMessageSize();

  /**
   * @brief Set protected mMessageSize field for unit test
   *
   * @param aData New value of mMessageSize
   */
  void ForTestSetMessageSize(int aSize);
  void ForTestConnect(QTcpSocket *aSocket);
  bool ForTestHasMessageCorrectFormat(char *aMessage);
  void ForTestSetMessage(char *aMessageFileChecksum);
  QTcpSocket *ForTestGetSocket();
  QByteArray *ForTestGetReveiveBuffer();

  /**
   * @brief Get protected mDataSize variable
   *        for unit tests
   *
   * @return Protected mDataSize variable
   */
  int32_t *ForTestGetDataSize();

  /**
   * @brief Call protected method ConvertMessageArrayToInt
   *
   * @return Checksum
   */
  int ForTestConvertMessageArrayToInt();

};

#endif // CReceiverWRAPPER_H
