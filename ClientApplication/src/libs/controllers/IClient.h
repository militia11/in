#ifndef ICLIENT_H
#define ICLIENT_H

#include <QObject>

class IClient : public QObject {
		Q_OBJECT

	public:
		///@todo opisy
    virtual bool WriteData(QByteArray aData) = 0;
		virtual bool WriteMessage(QByteArray aData) = 0;
		virtual QByteArray PrepareMessageData(int16_t aChecksum) = 0;
		virtual QByteArray IntToArray(int32_t aSource) = 0;

		/**
		 * @brief UpdateServerPhotos calculates checksums
		 *				of photos stored on mobile device and update
		 *				server photos
		 */
		virtual void UpdateServerPhotos() = 0;
		///@todo opisy
		virtual QByteArray ConvertImageToByteArray(QImage aImage) = 0;

	public slots:
		///@todo opisy
		virtual void ReadData() = 0;
		virtual bool ConnectToHost(QString aHost) = 0;

	private:
		virtual int16_t CalculateFileDataChecksum(QByteArray aData) = 0;
};

#endif // ICLIENT_H
