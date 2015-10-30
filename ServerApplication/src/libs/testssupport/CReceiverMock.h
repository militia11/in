#ifndef CReceiverMOCK_H
#define CReceiverMOCK_H

#include "libs/controllers/IReceiver.h"

/**
 * @brief Mock of CReceiver used in unit tests
 */
class CReceiverMock : public IReceiver {
  public:

    /**
     * @brief GetLog get actual log
     * @return Log
     */
		const QString GetLog() const;

    /**
		 * @brief Method called when server receive incoming connection,
		 *        client is connecting to specify port
     */
    void Connect(QTcpSocket *aSocket);

		/**
     * @brief Mock of ResponeToClient method
     */
    void ResponeToClient(QByteArray aData = 0);

    /**
     * @brief Mock of GetSocket method
		 * @return CReceiver socket
     */
    QTcpSocket *GetSocket() const;

    /**
     * @brief Mock of NewData method
     */
    void NewData();

    /**
     * @brief Mock of Disconnected method
     */
    void Disconnected();

    /**
     * @brief Mock of ConvertMessageArrayToInt method
     */
    int ConvertMessageArrayToInt();

    /**
     * @brief Mock of ServeReceivedFileData method
     */
    void ServeReceivedFileData();

    /**
     * @brief Mock of ByteArrayToInt method
     *
     * @param aData array
     *
     * @return Integer number converted from array
     */
    int32_t ByteArrayToInt(QByteArray aData);

    /**
     * @brief Mock of RouteData method
     *
     * @param aData is data to route
     */
    void RouteData(char aData);

    /**
     * @brief Mock of ServeReceivedMessage method
     */
    void ServeReceivedMessage();

    /**
     * @brief Mock of HasMessageCorrectFormatCheck method
     *
     * Message should consist from:
     * - message begin chars: ">>"
     * - data as hex-ascii string
     * - end message char: "<"
     *
     * @return True for correct format, False for incorrect
     */
    bool HasMessageCorrectFormat(char *aMessage);

    /**
     * @brief Mock of CalculateFileDataChecksum method
     *
     * @return Checksum calculated as youngest byte of sum of all bytes
     */
    uint16_t CalculateFileDataChecksum(QByteArray aData);

    /**
     * @brief Mock of ConnectSocketSignals method
     */
    inline void ConnectSocketSignals();

  protected:
    /**
     * @brief Log of called methods
     */
		mutable QString mLog;
};

#endif // CReceiverMOCK_H
