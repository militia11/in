#ifndef CCLIENTWRAPPER_H
#define CCLIENTWRAPPER_H

#include <QTcpSocket>

#include "src/libs/controllers/CClient.h"

/**
 * @brief Wrapper for CClient class
 *
 * Used to access protected variables, functions in tests
 */
class CClientWrapper : public CClient {
  public:
    /**
     * @brief CClientWrapper constructor
     *
     * @param aSocket Socket for client
     */
    CClientWrapper(QTcpSocket *aSocket);

    /**
     * @brief ForTestIntToArray Use to call protected method IntToArray
     *        for unit tests
     *
     * @param aSource Source is integer
     * @return QByteArray Array of bytes
     */
    QByteArray ForTestIntToArray(int32_t aSource);

    /**
     * @brief PrepareMessageData Call protected method PrepareMessageData
     *        for unit tests
     *
     * @param aChecksum Convert to message QByteArray
     * @return QByteArray Message
     */
    QByteArray ForTestPrepareMessageData (int16_t aChecksum);

    /**
     * @brief ForTestReadData Call protected method ReadData
     *        for unit tests
     */
    void ForTestReadData();

};

#endif // CCLIENTWRAPPER_H
