#ifndef CSERVERWRAPPER_H
#define CSERVERWRAPPER_H

#include "src/libs/controllers/CServer.h"

/**
 * @brief Wrapper for CServer class
 *
 * Used to access protected variables, functions in tests
 *
 */
class CServerWrapper : public CServer {
  public:
    /**
     * @brief Constructor with dependency-injection
     *
     * @param aReceiversFactory Factory of receivers
     */
    CServerWrapper(IReceiverFactory *aReceiversFactory);

    /**
     * @brief ForTestGetPortNumber method return protected field for unit tests
     *
     * @return Protected mPortNumber variable
     */
    int ForTestGetPortNumber();

    /**
     * @brief ForTestIncomingConnection call protected method
     *        IncomingConnection for unit tests
     */
    void ForTestIncomingConnection();

    /**
     * @brief ForTestSetPortNumber
     * @param aPortNumber Port number to set
     */
    void ForTestSetPortNumber(int aPortNumber);

    /**
     * @brief ForTestUpdatePortNumber call protected method
     *        UpdatePortNumber for unit tests
     */
    void ForTestUpdatePortNumber();
};

#endif // CSERVERWRAPPER_H
