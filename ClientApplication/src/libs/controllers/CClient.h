#ifndef CCLIENT_H
#define CCLIENT_H

#include <inttypes.h> //uint_t* and int_t* types

#include <QByteArray>
#include <QObject>
#include <QtCore>
#include <QtNetwork>

#include "src/libs/controllers/CClient.h"

/**
 * @brief The serverAvailability enum. State of response message
 */
enum serverAvailability {
  status_unknown = -1,
  status_in_server = 1,
  status_not_available = 2
};

/**
 * @brief The CClient class represent client in
 *        client-server architecture
 */
class CClient : public QObject {
  Q_OBJECT

 public:
  /**
   * @brief CClient class constructor
   */
  CClient(QTcpSocket *aSocket);

  /**
   * @brief CClient class destructor
   */
  ~CClient();

  /**
   * @brief WriteData write file data to socket
   *
   * @param aData data to write
   * @return True if write successfull, otherwise false
   */
  virtual bool WriteData(const QByteArray &aData);

  /**
   * @brief WriteMessage write message to socket
   *
   * @param aData Message to write
   * @return True if write successfull, otherwise false
   */
  virtual bool WriteMessage(const QByteArray &aData);

  /**
   * @brief UpdateServerPhotos calculates checksums
   *        of photos stored on mobile device and update
   *        server photos
   */
  virtual void UpdateServerPhotos();

  /**
   * @brief ConvertImageToByteArray method convert imaqe to
   *        QByteArray
   *
   * @param aImage Image to convert
   * @return Converted image to QByteArray
   */
  virtual QByteArray ConvertImageToByteArray(const QImage &aImage);

  /**
   * @brief Check photo
   *
   * @param aPhotoNumber Photo number
   */
  void CheckPhoto(int aPhotoNumber);

 signals:
  void action(int num);

  /**
   * @brief Set status
   *
   * @param aMessage Message
   */
  void SetStatus(QString aMessage);

 public slots:
  /**
   * @brief ConnectToHost method connect to host
   *
   * @param aHost is hostname/number
   */
  virtual bool ConnectToHost(QString aHost);

 protected slots:
  /**
   * @brief ReadData method read received data
   */
  virtual void ReadData();

 protected:
  /**
   * @brief WaitForChangeStatus Wait for change status
   *
   * Wait 10 seconds until status changed or timeout end
   */
  void WaitForChangeStatus();

  /**
   * @brief ManageData manage data
   *
   * @param aData Data to send
   */
  void ManageData(QByteArray aData);

  /**
   * @brief CalculateFileDataChecksum calculate file checksum
   *
   * @param aData Byte array of data
   * @return Checksum
   */
  virtual uint32_t CalculateFileDataChecksum(QByteArray aData);

  /**
   * @brief IntToArray Convert integer to QByteArray
   *
   * @param aSource Source is integer
   * @return QByteArray Array of bytes
   */
  virtual QByteArray IntToArray(int32_t aSource);

  /**
   * @brief PrepareMessageData prepare message data
   *
   * @param aChecksum Convert to message QByteArray
   * @return QByteArray Message
   */
  virtual QByteArray PrepareMessageData(uint32_t aChecksum);

  /**
   * @brief mPortNumber Port number
   */
  int         mPortNumber;

  /**
   * @brief mServerAvailability Server availability
   */
  volatile serverAvailability mServerAvailability;

  /**
   * @brief mSocket Socket
   */
  QTcpSocket  *mSocket;

  /**
   * @brief mReceiveBuffer Receive buffer
   */
  QByteArray  *mReceiveBuffer;

  /**
   * @brief mActualData Actual data
   */
  QByteArray  mActualData;
  volatile bool mSend;
};
#endif // CCLIENT_H
