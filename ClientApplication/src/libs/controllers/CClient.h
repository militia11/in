#ifndef CCLIENT_H
#define CCLIENT_H

#include <inttypes.h> //uint_t* and int_t* types

#include <QByteArray>
#include <QtCore>
#include <QtNetwork>

#include "libs/controllers/IClient.h"

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
    bool WriteData(QByteArray aData);

    /**
     * @brief WriteMessage write message to socket
     *
     * @param aData message to write
     * @return True if write successfull, otherwise false
     */
    bool WriteMessage(QByteArray aData);

    /**
     * @brief PrepareMessageData prepare message data
     *
     * @param aChecksum Convert to message QByteArray
     * @return QByteArray Message
     */
    QByteArray PrepareMessageData(int16_t aChecksum);

    /**
     * @brief IntToArray Convert integer to QByteArray
     *
     * @param aSource is integer
     * @return QByteArray
     */
    QByteArray IntToArray(int32_t aSource);

    /**
     * @brief UpdateServerPhotos calculates checksums
     *				of photos stored on mobile device and update
     *				server photos
     */
    void UpdateServerPhotos();

    /**
     * @brief ConvertImageToByteArray method convert imaqe to
     *        QByteArray
     * @param aImage Image to convert
     * @return Converted image to QByteArray
     */
    QByteArray ConvertImageToByteArray(QImage aImage);

  public slots:
    ///@todo opisy
    void ReadData();
    bool ConnectToHost(QString aHost);

	protected:
    int16_t CalculateFileDataChecksum(QByteArray aData);

    bool mFileToSend;
    QTcpSocket *mSocket;
    QByteArray *mReceiveBuffer;
    QByteArray mActualData;
};
#endif // CCLIENT_H
