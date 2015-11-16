#ifndef CReceiverWRAPPER_H
#define CReceiverWRAPPER_H

#include <inttypes.h>  // uint_t* and int_t* types

#include "src/libs/controllers/CReceiver.h"

/**
 * @brief Wrapper for CReceiver class
 *
 * Used to access protected variables in tests
 */
class CReceiverWrapper : public CReceiver {
 public:

void ForTestConnect(QTcpSocket *aSocket);
void ForTestDisconnected();
  /**
   * @brief ForTestNewData call protected method NewData
   *        for unit tests
   */
  void ForTestNewData();
  void ForTestRouteData(char aData);

	/**
	 * @brief ForTestServeReceivedFileData call protected method
	 *        ServeReceivedFileData for unit tests
	 */
	void ForTestServeReceivedFileData();

  void ForTestServeReceivedMessage();

  u_int16_t ForTestCalculateFileDataChecksum(QByteArray aData);

  /**
   * @brief Set protected mMessageSize field for unit test
   *
   * @param aData New value of mMessageSize
   */
  void ForTestSetMessageSize(int aSize);


  void ForTestSetReceiveByteCount(int aByteCount);
  bool ForTestHasMessageCorrectFormat(char *aMessage);
  void ForTestSetReceiveDataMode(ReceiveDataMode aMode);
  void ForTestSetMessage(char *aMessageFileChecksum);
  void ForTestSetSocket(QTcpSocket *aSocket);
  void ForTestSetReceiveBuffer(QByteArray *aBuffer);
  void ForTestSetDataSize(int32_t *aDataSize);

  /**
   * @brief ForTestGetReceiveDataMode Get protected mReceiveDataMode variable for unit tests
   *
   * @return protected mReceiveDataMode variable
   */
  ReceiveDataMode ForTestGetReceiveDataMode();
  char *ForTestGetMessageFileChecksum();
  int ForTestGetMessageSize();
  int ForTestGetReceiveByteCount();
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
