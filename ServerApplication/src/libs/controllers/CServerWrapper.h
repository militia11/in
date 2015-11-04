#ifndef CSERVERWRAPPER_H
#define CSERVERWRAPPER_H

#include "../ServerApplication/src/libs/controllers/CServer.h"

/**
 * @brief Wrapper for CServer class
 *
 * Used to acces to some private/protected variables, functions in tests
 *
 */
class CServerWrapper : public CServer
{
  public:
    /**
     * @brief Constructor with dependency-injection
     * @todo może napisac o tym w pracy?
     */
    CServerWrapper(IReceiverFactory *aReceiversFactory);
    void TestIncomingConnection();
    void ForTestSetPortNumber(int aPortNumber);
    int TestGetPortNumber();
    void TestUpdatePortNumber();
};

/*
QByteArray CGODWrapper::TestFormatSendMessage(
  const QByteArray &aMessage,
  char aTargetModule
) {
  return FormatSendMessage(aMessage, aTargetModule);
}
*/
#endif // CSERVERWRAPPER_H
