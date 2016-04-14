#ifndef CReceiver_H
#define CReceiver_H

#include <inttypes.h>  // uint_t* and int_t* types

#include <QTcpSocket>
#include <QObject>

#include "src/libs/controllers/CRetrievePhotoTransaction.h"
#include "src/libs/controllers/CStorePhotoTransaction.h"
#include "src/libs/controllers/IReceiver.h"
#include "src/libs/dao/CChecksumList.h"

/**
 * @brief The ReceiveDataMode is enumeration of kinds receive data
 *        modes for Receiver
 */
enum ReceiveDataMode {
  Mode_Receive_File_Data      = 1,
  Mode_Receive_File_Checksum  = 2
};

/**
 * @brief The CReceiver class receive photos from client in
 *        client-server architecture
 *
 * CReceiver class inherits from QObject. This class have responsibility
 * of coordinate communication with CReceiver class from Android-side application
 */
class CReceiver : public IReceiver {
  Q_OBJECT

 public:
  /**
   * @brief CReceiver constructor
   */
  CReceiver();

  /**
   * @brief CReceiver destructor
   */
  ~CReceiver();

  /**
   * @brief Method called to get CReceiver class member mSocket
   *        which represent socket
   *
   * @return CReceiver socket
   */
  QTcpSocket *GetSocket() const;

 protected slots:
  /**
   * @brief Slot called when connection lost
   */
  void Disconnected();

  /**
   * @brief Method called when new incomming data received
   */
  void NewData();

 signals:
  /**
   * @brief Signal emited when client disconnect from server
   */
  void Disconnect();

  /**
   * @brief Signal emited when error occured a socket
   *
   * @param aSocketError is a QTcpSocket::SocketError
   */
  void Error(QTcpSocket::SocketError aSocketError);

  /**
   * @brief Signal emited when was read data
   *
   * @param aData is a QByteArray data which was read
   */
  void ReadData(QByteArray aData);

  /**
   * @brief MessageStatus  Signal emited to send status for mainly to the main status bar
   *
   * @param aMessage Message to send
   * @param aTimeMsc Time in miliseconds
   */
  void MessageStatus(const char *aMessage, int aTimeMsc);

  /**
   * @brief Receive data progress changed
   *
   * @param aProgress Progress
   */
  void ReceiveDataProgressChanged(int aProgress);

 protected:
  /**
   * @brief Calculate progress
   */
  void CalculateProgress();

  /**
   * @brief RemoveSizeFromBuffer Remove current size from buffer
   */
  void RemoveSizeFromBuffer();

  /**
   * @brief SaveAndSetCurrentSize Set and save current size to class member
   */
  void SaveAndSetCurrentSize(int32_t *aCurrentSize);

  /**
   * @brief StoreData Store data to database
   *
   * @param aCurrentSize Size of data to store
   */
  void StoreData(int32_t aCurrentSize);

  /**
   * @brief NotPunk Verify if size is not punk
   *
   * @param aSize Size to verify
   * @return True if is not punk, otherwise false
   */
  bool NotPunk(int32_t aSize);

  /**
   * @brief HasDataReceivedCompletely Verify if data has received completely
   *
   * @return True if data has received completely, otherwise false
   */
  bool HasDataReceivedCompletely();

  /**
   * @brief HasSizeOfDataReceivedCompletely Verify if size of data
   *        has received completely
   *
   * @return True if size of data has received completely, otherwise false
   */
  bool HasSizeOfDataReceivedCompletely();

  /**
   * @brief CanReceive Verify if can proceed
   *        of receive data from device
   *
   * @return True if can receive, otherwise false
   */
  bool CanReceive();

  /**
   * @brief IsBytesAvailable Verify if bytes available in socket
   *
   * @return True if bytes available, otherwise false
   */
  bool IsBytesAvailable();

  /**
   * @brief CleanSizesFields Clean sizes fields
   *
   * @param aCurrentSize Current size to clear
   */
  void CleanSizesFields(int *aCurrentSize);

  /**
   * @brief RemoveDataFromBuffer Remove data from buffer
   *
   * @param aCurrentSize Current size
   */
  void RemoveDataFromBuffer(int32_t aCurrentSize);

  /**
   * @brief TryServeReceivedMessage Try call ServeReceivedMessage method
   */
  void TryServeReceivedMessage();

  /**
   * @brief PrepareBuffersToReceiveDataMode Prepare buffers to
   *        Mode_Receive_File_Data
   */
  void PrepareBuffersToReceiveDataMode();

  /**
   * @brief NotChecksumInServer Verify if checksum is in server
   *
   * @return True if checksum is not in server, otherwise false
   */
  bool NotChecksumInServer();

  /**
   * @brief CleanBuffers Clean buffers
   */
  void CleanBuffers();

  /**
   * @brief VerifyMessageFormat Call HasMessageCorrectFormat method and throw
   *        exception when message format is not correct
   */
  void VerifyMessageFormat();

  /**
   * @brief AppendToChecksum Append next sign to checksum
   *
   * @param aData Data to append
   */
  void AppendToChecksum(char aData);

  /**
   * @brief IsEndMessageChar Verify if it is end message char
   *
   * @param aData Char to verify
   * @return True if it is end message char, otherwise false
   */
  bool IsEndMessageChar(char aData);

  /**
   * @brief PreventBufferOverflow Prevent buffer overflow
   */
  void PreventBufferOverflow();

  /**
   * @brief SetChecksumMode Set Mode_Receive_File_Checksum mode
   */
  void SetChecksumMode();

  /**
   * @brief IsBeginChar Verify if it is begin char
   *
   * @param aChar Char to verify
   * @return True if begin char, otherwise false
   */
  bool IsBeginChar(char aChar);

  /**
   * @brief VerifyBeginMessage Check if begin message
   *
   * @param aData Byte array
   * @param aPosition Current position
   */
  void VerifyBeginMessage(QByteArray aData, int aPosition);

  /**
   * @brief ExecuteConnectActions execute connect actions
   */
  void ExecuteConnectActions(QTcpSocket *aSocket);

  /**
   * @brief EmitNotConnectedStatus Emit not connected status
   */
  void EmitNotConnectedStatus();

  /**
   * @brief MessageFormatException print message format exception
   *
   * @param aException is message exception
   */
  void MessageFormatException(const char *aException);

  /**
   * @brief Method to respone information to client
   *
   * @param aMessage is Message to send
   */
  void ResponeToClient(const char *aMessage = 0);

  /**
   * @brief Method called when server receive incoming connection,
   *        client is connecting to specify port
   */
  void Connect(QTcpSocket *aSocket);

  /**
   * @brief ConvertMessageArrayToInt method convert message
   *        to int
   *
   * @return Checksum
   */
  int ConvertMessageArrayToInt();

  /**
   * @brief ServeFileData serve file data
   *        from incoming connection
   */
  void ServeReceivedFileData();

  /**
   * @brief ByteArrayToInt convert array to int
   *
   * @param aData Array of data
   * @return Integer number converted from array
   */
  int32_t ByteArrayToInt(QByteArray aData);

  /**
   * @brief RouteData function switch data to
   *        CCheckSumList class or file data to save
   *        in server
   *
   * @param aData is data to route
   */
  void RouteData(char aData);

  /**
   * @brief Serve single received message
   */
  void ServeReceivedMessage();

  /**
   * @brief Check has message correct format
   *
   * Message should consist from:
   * - message begin chars: ">>"
   * - data as hex-ascii string
   * - end message char: "<"
   *
   * @param aMessage Message to check
   *
   * @return True for correct format, false for incorrect
   */
  bool HasMessageCorrectFormat(char *aMessage);

  /**
   * @brief CalculateFileDataChecksum calculate message checksum
   *        to compare with expected
   *
   * @return Checksum calculated as youngest byte of sum of all bytes
   */
  int32_t CalculateFileDataChecksum(QByteArray aData);

  /**
   * @brief Method connect socket's signals to
   *        represent client's (CReceiver) slots
   */
  void ConnectSocketSignals();

  /**
   * @brief mSocket of client
   */
  QTcpSocket *mSocket;

  /**
   * @brief mReceiveBuffer is buffer of received data
   */
  QByteArray *mReceiveBuffer;

  /**
   * @brief mDataSize is size of receive buffer
   */
  int32_t *mDataSize;

  /**
   * @brief mReceiveDataMode is mode of receiving data
   */
  ReceiveDataMode mReceiveDataMode;

  /**
   * @brief mMessageClntFileChecksum is checksum of file sended
   *        from client
   */
  char mMessageFileChecksum[1024];

  /**
   * @brief mMessageSize is size of message sended from client
   */
  int mMessageSize;

  /**
   * @brief mReceiveByteCount is counter of received bytes
   */
  int mReceiveByteCount;
};

#endif // CReceiver_H
