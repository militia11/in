#ifndef ICLIENT_H
#define ICLIENT_H

#include <QObject>

class IClient : public QObject {
		Q_OBJECT

	public:
		/**
		 * @brief WriteData write file data to socket
		 *
		 * @param aData data to write
		 * @return True if write successfull, otherwise false
		 */
    virtual bool WriteData(QByteArray aData) = 0;

		/**
		 * @brief WriteMessage write message to socket
		 *
		 * @param aData message to write
		 * @return True if write successfull, otherwise false
		 */
		virtual bool WriteMessage(QByteArray aData) = 0;

		/**
		 * @brief PrepareMessageData prepare message data
		 *
		 * @param aChecksum Convert to message QByteArray
		 * @return QByteArray Message
		 */
		virtual QByteArray PrepareMessageData(int16_t aChecksum) = 0;

		/**
		 * @brief IntToArray Convert integer to QByteArray
		 *
		 * @param aSource is integer
		 * @return QByteArray
		 */
		virtual QByteArray IntToArray(int32_t aSource) = 0;

		/**
		 * @brief UpdateServerPhotos calculates checksums
		 *				of photos stored on mobile device and update
		 *				server photos
		 */
		virtual void UpdateServerPhotos() = 0;

		/**
		 * @brief ConvertImageToByteArray method convert imaqe to
		 *        QByteArray
		 * @param aImage Image to convert
		 * @return Converted image to QByteArray
		 */
    virtual QByteArray ConvertImageToByteArray(const QImage &aImage) = 0;

	public slots:
		/**
		 * @brief ReadData method read received data
		 */
		virtual void ReadData() = 0;

		/**
		 * @brief ConnectToHost method connect to host
		 *
		 * @param aHost is host name/number
		 */
		virtual bool ConnectToHost(QString aHost) = 0;

	private:
		/**
		 * @brief CalculateFileDataChecksum calculate file checksum
		 *
		 * @param aData Byte array of data
		 * @return Checksum
		 */
		virtual int16_t CalculateFileDataChecksum(QByteArray aData) = 0;
};

#endif // ICLIENT_H
