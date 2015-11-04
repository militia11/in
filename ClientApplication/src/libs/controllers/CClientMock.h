#ifndef CCLIENTMOCK_H
#define CCLIENTMOCK_H

#include "../ClientApplication/src/libs/controllers/IClient.h"

#include <QByteArray>
#include <QImage>
#include <QObject>
class CClientMock : public IClient {
		Q_OBJECT
	public:
		/**
			* @brief GetLog get actual log
			* @return Log
			*/
		const QString GetLog() const;

		/**
		 * @brief Mock of WriteData method
		 *
		 * @param aData data to write
		 * @return True if write successfull, otherwise false
		 */
		virtual bool WriteData(QByteArray aData);

		/**
		 * @brief Mock of WriteMessage method
		 *
		 * @param aData message to write
		 * @return True if write successfull, otherwise false
		 */
		virtual bool WriteMessage(QByteArray aData);

		/**
		 * @brief Mock of PrepareMessageData method
		 *
		 * @param aChecksum Convert to message QByteArray
		 * @return QByteArray Message
		 */
		virtual QByteArray PrepareMessageData(int16_t aChecksum);

		/**
		 * @brief Mock of IntToArray method
		 *
		 * @param aSource is integer
		 * @return QByteArray
		 */
		virtual QByteArray IntToArray(int32_t aSource);

		/**
		 * @brief Mock of UpdateServerPhotos method
		 *        of photos stored on mobile device and update
		 *        server photos
		 */
		virtual void UpdateServerPhotos();

		/**
		 * @brief Mock of ConvertImageToByteArray method
		 *
		 * @param aImage Image to convert
		 * @return Converted image to QByteArray
		 */
		virtual QByteArray ConvertImageToByteArray(const QImage &aImage);

		/**
		 * @brief Mock of ReadData method
		 */
		virtual void ReadData();

		/**
		 * @brief Mock of ConnectToHost method
		 *
		 * @param aHost is host name/number
		 */
		virtual bool ConnectToHost(QString aHost);

		/**
		 * @brief Mock of CalculateFileDataChecksum method
		 *
		 * @param aData Byte array of data
		 * @return Checksum
		 */
		virtual int16_t CalculateFileDataChecksum(QByteArray aData);

	protected:
		/**
		 * @brief Log of called methods
		 */
		mutable QString mLog;
};

#endif // CCLIENTMOCK_H
