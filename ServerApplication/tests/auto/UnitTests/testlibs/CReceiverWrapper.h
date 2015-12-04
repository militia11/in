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
    /**
     * @brief ForTestRemoveSizeFromBuffer call protected method
     *        RemoveSizeFromBuffer for unit tests
     */
    void ForTestRemoveSizeFromBuffer();

  /**
   * @brief ForTestHasDataReceivedCompletely call protected method
   *        HasDataReceivedCompletely for unit tests
   *
   * @return True if data has received completely, otherwise false
   */
  bool ForTestHasDataReceivedCompletely();

  /**
   * @brief ForTestConnect call protected method Connect
   *        for unit tests
   *
   * @param aSocket Socket
   */
  void ForTestConnect(QTcpSocket *aSocket);

  /**
   * @brief ForTestDisconnectedcall protected method Disconnected
   *        for unit tests
   */
  void ForTestDisconnected();

  /**
   * @brief ForTestNewData call protected method NewData
   *        for unit tests
   */
  void ForTestNewData();

  /**
   * @brief ForTestRouteData call protected method RouteData
   *        for unit tests
   *
   * @param aData
   */
  void ForTestRouteData(char aData);

  /**
   * @brief ForTestServeReceivedFileData call protected method
   *        ServeReceivedFileData for unit tests
   */
  void ForTestServeReceivedFileData();

  /**
   * @brief ForTestServeReceivedMessage call protected method
   *        ServeReceivedMessage for unit tests
   */
  void ForTestServeReceivedMessage();

  u_int16_t ForTestCalculateFileDataChecksum(QByteArray aData);

  /**
   * @brief Set protected mMessageSize field for unit test
   *
   * @param aSize New message size
   */
  void ForTestSetMessageSize(int aSize);

  /**
   * @brief ForTestSetReceiveByteCount Set protected field
   *        mReceiveByteCount for unit tests
   *
   * @param aByteCount New Receive byte count
   */
  void ForTestSetReceiveByteCount(int aByteCount);

  /**
   * @brief ForTestHasMessageCorrectFormat call protected method
   *        HasMessageCorrectFormat for unit tests
   *
   * Message should consist from:
   * - message begin chars: ">>"
   * - data as hex-ascii string
   * - end message char: "<"
   *
   * @param aMessage Message to check
   * @return True for correct format, False for incorrect
   */
  bool ForTestHasMessageCorrectFormat(char *aMessage);

  /**
   * @brief ForTestSetReceiveDataMode Set protected field mReceiveDataMode
   *        for unit tests
   *
   * @param aMode Mode to set
   */
  void ForTestSetReceiveDataMode(ReceiveDataMode aMode);

  /**
   * @brief ForTestSetMessage Set protected field mMessageFileChecksum
   *        for unit tests
   *
   * @param aMessageFileChecksum Message file checksum to set
   */
  void ForTestSetMessage(char *aMessageFileChecksum);

  /**
   * @brief ForTestSetSocket Set protected field mSocket
   *        for unit tests
   *
   *  @param aSocket Socket to set
   */
  void ForTestSetSocket(QTcpSocket *aSocket);

  /**
   * @brief ForTestSetReceiveBuffer Set protected field
   *        mReceiveBuffer for unit tests
   *
   * @param aBuffer Buffer to set
   */
  void ForTestSetReceiveBuffer(QByteArray *aBuffer);

  /**
   * @brief ForTestSetDataSize Set protected field mDataSize
   *        for unit tests
   *
   * @param aDataSize Data size to set
   */
  void ForTestSetDataSize(int32_t *aDataSize);

  /**
   * @brief ForTestGetReceiveDataMode Get protected mReceiveDataMode
   *        variable for unit tests
   *
   * @return protected mReceiveDataMode variable
   */
  ReceiveDataMode ForTestGetReceiveDataMode();

  /**
   * @brief ForTestGetMessageFileChecksum
   *
   * @return
   */
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
