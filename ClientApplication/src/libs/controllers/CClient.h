#ifndef CCLIENT_H
#define CCLIENT_H

#include <inttypes.h> //uint_t* and int_t* types

#include <QByteArray>
#include <QtCore>
#include <QtNetwork>

class CClient : public QObject {
    Q_OBJECT

  public:
    explicit CClient(QObject *aParent = 0);
		~CClient();

		bool WriteData(QByteArray aData);
    bool WriteMessage(QByteArray aData);
		QByteArray PrepareMessageData(int16_t aChecksum);
		QByteArray IntToArray(int32_t aSource);

		/**
		 * @brief UpdateServerPhotos calculates checksums
		 *				of photos stored on mobile device and update
		 *				server photos
		 */
		void UpdateServerPhotos();
		///@todo opisy
		QByteArray ConvertImageToByteArray(QImage aImage);

  public slots:
		///@todo opisy
    void ReadData();
    bool ConnectToHost(QString aHost);

  private:
		int16_t CalculateFileDataChecksum(QByteArray aData);

		bool mFileToSend;
    QTcpSocket *mSocket;
    QByteArray *mReceiveBuffer;
		QByteArray mActualData;
};
#endif // CCLIENT_H
