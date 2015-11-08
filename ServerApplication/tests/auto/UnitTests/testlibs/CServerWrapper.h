#ifndef CSERVERWRAPPER_H
#define CSERVERWRAPPER_H

#include "src/libs/controllers/CServer.h"

/**
 * @brief Wrapper for CServer class
 *
 * Used to acces private/protected variables, functions in tests
 *
 */
class CServerWrapper : public CServer {
  public:
    /**
     * @brief Constructor with dependency-injection
     * @todo może napisac o tym w pracy?
     */
    CServerWrapper(IReceiverFactory *aReceiversFactory);
    void ForTestIncomingConnection();
    void ForTestSetPortNumber(int aPortNumber);
    int ForTestGetPortNumber();
    void ForTestUpdatePortNumber();
};

#endif // CSERVERWRAPPER_H
