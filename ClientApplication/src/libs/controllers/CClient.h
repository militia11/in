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
    bool WriteData(QByteArray aData);
    bool WriteMessage(QByteArray aData);
    bool PrepareMessageData();

  public slots:
    void ReadData();
    bool ConnectToHost(QString aHost);

  private:

    uint8_t CalculateMessageChecksum(QByteArray aData);
    void ConvertBinaryToHexAscii(const char *aData, int aLen,
                                 char *aTarget);

    QTcpSocket *mSocket;
    QByteArray *mReceiveBuffer;
    QByteArray *mActualData;
    char mSendBuffer[2048];
};
#endif // CCLIENT_H
