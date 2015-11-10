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
	void ForTestNewData();
	void ForTestRouteData(char aData);
void ForTestConnect(QTcpSocket *aSocket);
void ForTestServeReceivedMessage();


/**
   * @brief Set protected mMessageSize field for unit test
   *
   * @param aData New value of mMessageSize
   */
  void ForTestSetMessageSize(int aSize);
	void  ForTestSetReceiveByteCount(int aByteCount);
  bool ForTestHasMessageCorrectFormat(char *aMessage);
	void ForTestSetReceiveDataMode(ReceiveDataMode aMode);
	void ForTestSetMessage(char *aMessageFileChecksum);
	QTcpSocket *ForTestSetSocket(QTcpSocket *aSocket);
	void ForTestSetReceiveBuffer(QByteArray *aBuffer);

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
