#ifndef CSERVERMOCK_H
#define CSERVERMOCK_H

#include "libs/controllers/IServer.h"
#include "libs/controllers/CReceiver.h"

#include <QString>
/**
 * @brief Mock of CReceiver used in unit tests
 */
class CServerMock : public IServer {
  public:
		const QString GetLog() const;

    /**
		 * @brief Mock of Run method
     */
    void Run();

    /**
		 * @brief Mock of StopListening method
     */
    void StopListening();

    /**
		 * @brief Mock of GetClient method
     *
		 * @return Object which represent  client class (CReceiver)
     */
    CReceiver *GetClient() const;

		private slots:
    /**
		 * @brief Mock of IncomingConnection method
     */
    void IncomingConnection();

    /**
		 * @brief Mock of ResumeAccepting method
     */
    void ResumeAccepting();

    /**
		 * @brief Mock of PauseAccepting method
     */
    void PauseAccepting();

    /**
		 * @brief Mock of ConnectClientSignals method
     */
    inline void ConnectClientSignals();

    /**
		 * @brief Mock of UpdatePortNum method
     */
    inline void UpdatePortNumber();

  protected:
    /**
     * @brief Log of called methods
     */
		mutable QString mLog;
};

#endif // CSERVERMOCK_H
