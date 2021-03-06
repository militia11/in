#ifndef CRECEIVERMOCKFACTORY_H
#define CRECEIVERMOCKFACTORY_H

#include "src/libs/controllers/IReceiverFactory.h"
#include "src/libs/controllers/IReceiver.h"

/**
 * @brief The CReceiverMockFactory class is factory of mocks
 *        CReceiverFactoryImplementation class
 */
class CReceiverMockFactory : public IReceiverFactory {
 public:
  /**
   * @brief Make Get Mock of CReceiverFactoryImplementation class
   *
   *  @return IReceiver object
   */
  IReceiver *Make();
};

#endif // CRECEIVERMOCKFACTORY_H
