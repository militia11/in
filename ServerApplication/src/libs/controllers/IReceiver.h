#ifndef IReceiver_H
#define IReceiver_H

#include <inttypes.h>
#include <stdio.h> // convert array to int function
#include <ctype.h> // isdigit function

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTcpSocket>

/**
 * @brief The IReceiver class is interface
 */
class IReceiver : public QObject {
		Q_OBJECT
  public:
    /**
     * @brief Method called when server receive incoming connection,
     *        client is connecting to specify port
     */
		virtual void Connect(QTcpSocket *aSocket) = 0;

    /**
     * @brief Method to respone information to client
     */
    virtual void ResponeToClient(QByteArray aData = 0) = 0;

    /**
     * @brief Method called to get CReceiver class member mSocket
     *        which represent socket
     *
     * @return CReceiver socket
     */
    virtual QTcpSocket *GetSocket() const = 0;

  //public slots:
    /**
     * @brief Method called on new incomming data
     */
    virtual void NewData() = 0;

  //private slots:
    /**
     * @brief Slot called when connection closed
     */
    virtual void Disconnected() = 0;

  //protected:
    ///@todo opis
    virtual int ConvertMessageArrayToInt() = 0;

    /**
     * @brief ServeFileData serve file data
     *        from incoming connection.
     */
    virtual void ServeReceivedFileData() = 0;

    /**
     * @brief ByteArrayToInt convert array to int
     *
     * @param aData array.
     *
     * @return Integer number converted from array
     */
    virtual int32_t ByteArrayToInt(QByteArray aData) = 0;

    /**
     * @brief RouteData function switch data to
     *        CCheckSumList class or file data to save
     *        in server
     *
     * @param aData is data to route
     */
    virtual void RouteData(char aData) = 0;

    /**
     * @brief Serve single received message
     */
    virtual void ServeReceivedMessage() = 0;

    /**
     * @brief Check has message correct format
     *
     * Message should consist from:
     * - message begin chars: ">>"
     * - data as hex-ascii string
     * - end message char: "<"
     *
     * @return True for correct format, False for incorrect
     */
    virtual bool HasMessageCorrectFormat(char *aMessage) = 0;

    /**
     * @brief CalculateFileDataChecksum calculate message checksum
     *		  to compare with expected
     *
     * @return Checksum calculated as youngest byte of sum of all bytes
     */
    virtual uint16_t CalculateFileDataChecksum(QByteArray aData) = 0;

    /**
     * @brief Method connect socket's signals to
     *        represent client's (CReceiver) slots
     */
    virtual inline void ConnectSocketSignals() = 0;
};

#endif // IReceiver_H
