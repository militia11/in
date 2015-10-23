#ifndef ICLIENT_H
#define ICLIENT_H

#include <inttypes.h>
#include <stdio.h> // convert array to int function
#include <ctype.h> // isdigit function

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTcpSocket>

//#include "libs/dao/CRepository.h"

/**
 * @brief The IClient class is interface of CClient class
 */
class IClient : public QObject {
  public:
    /**
    * @brief CClient destructor.
    */
    //~ CClient();

    /**
     * @brief Method called when server receive incoming connection,
     *		  client is connecting to specify port.
     */
    virtual void Connect(QTcpSocket *aSocket) = 0;

    /**
     * @brief Method to respone information to client.
     */
    virtual void ResponeToClient(QByteArray aData = 0) = 0;

    /**
     * @brief Method called to get CClient class member mSocket
     *		  which represent socket.
     *
     * @return CCLient socket.
     */
    virtual QTcpSocket *GetSocket() const = 0;

  public slots:
    /**
     * @brief Method called on new incomming data.
     */
    virtual void NewData() = 0;

  signals:
    /**
     * @brief Signal emited when client disconnect from server.
     */
    virtual void Disconnect() = 0;

    /**
     * @brief Signal emited when error occured a socket.
     *
     * @param aSocketError is a QTcpSocket::SocketError.
     */
    virtual void Error(QTcpSocket::SocketError aSocketError) = 0;

    /**
     * @brief Signal emited when was read data.
     *
     * @param aData is a QByteArray data which was read.
     */
    virtual void ReadData(QByteArray aData) = 0;

    /**
     * @brief Signal emited to send status for mainly to the main status bar.
     */
    virtual void MessageStatus(const char *aMessage, int aTimeMsc) = 0;

  private slots:
    /**
     * @brief Slot called when connection closed.
     */
    virtual void Disconnected() = 0;

  protected:
    ///@todo opis
    virtual int ConvertMessageArrayToInt() = 0;

    /**
     * @brief ServeFileData serve file data
     *		  from incoming connection.
     */
    virtual void ServeReceivedFileData() = 0;

    /**
     * @brief ByteArrayToInt convert array to int.
     *
     * @param aData array.
     *
     * @return Integer number converted from array.
     */
    virtual int32_t ByteArrayToInt(QByteArray aData) = 0;

    /**
     * @brief RouteData function switch data to
     *        CCheckSumList class or file data to save
     *        in server.
     *
     * @param aData is data to route.
     */
    virtual void RouteData(char aData) = 0;

    /**
     * @brief Serve single received message.
     */
    virtual void ServeReceivedMessage() = 0;

    /**
     * @brief Check has message correct format.
     *
     * Message should consist from:
     * - message begin char: ">"
     * - data as hex-ascii string
     * - end message char: "<"
     *
     * @return True for correct format, False for incorrect.
     */
    virtual bool HasMessageCorrectFormat(char *aMessage) = 0;

    /**
     * @brief CalculateFileDataChecksum calculate message checksum
     *		  to compare with expected.
     *
     * @return Checksum calculated as youngest byte of sum of all bytes.
     */
    virtual uint16_t CalculateFileDataChecksum(QByteArray aData) = 0;

    /**
     * @brief Method connect socket's signals to
     *        represent client's (CClient) slots.
     */
    virtual inline void ConnectSocketSignals() = 0;

};

#endif // ICLIENT_H
