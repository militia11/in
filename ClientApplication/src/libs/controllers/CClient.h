#ifndef CCLIENT_H
#define CCLIENT_H

#include <inttypes.h> //uint_t* and int_t* types

#include <QByteArray>
#include <QtCore>
#include <QtNetwork>

#include "src/libs/controllers/IClient.h"

/**
 * @brief The CClient class represent client in
 *        client-server architecture
 */
class CReceiver : public IClient {
		Q_OBJECT

  public:
    /**
     * @brief CClient class constructor
     */
		CReceiver();

    /**
     * @brief CClient class destructor
     */
		~CReceiver();

    /**
     * @brief WriteData write file data to socket
     *
     * @param aData data to write
     * @return True if write successfull, otherwise false
     */
		virtual bool WriteData(QByteArray aData);

    /**
     * @brief WriteMessage write message to socket
     *
     * @param aData message to write
     * @return True if write successfull, otherwise false
     */
		virtual bool WriteMessage(QByteArray aData);

    /**
     * @brief PrepareMessageData prepare message data
     *
     * @param aChecksum Convert to message QByteArray
     * @return QByteArray Message
     */
		virtual QByteArray PrepareMessageData(int16_t aChecksum);

    /**
     * @brief IntToArray Convert integer to QByteArray
     *
     * @param aSource is integer
     * @return QByteArray
     */
		virtual QByteArray IntToArray(int32_t aSource);

    /**
     * @brief UpdateServerPhotos calculates checksums
     *				of photos stored on mobile device and update
     *				server photos
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

  public slots:
		/**
		 * @brief ReadData method read received data
		 */
		virtual void ReadData();

		/**
		 * @brief ConnectToHost method connect to host
		 *
		 * @param aHost is hostname/number
		 */
		virtual bool ConnectToHost(QString aHost);

	protected:
		/**
		 * @brief CalculateFileDataChecksum calculate file checksum
		 *
		 * @param aData Byte array of data
		 * @return Checksum
		 */
		virtual int16_t CalculateFileDataChecksum(QByteArray aData);

		bool        mSendFile;
		QTcpSocket  *mSocket;
		QByteArray  *mReceiveBuffer;
		QByteArray  mActualData;
};
#endif // CCLIENT_H
