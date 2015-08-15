#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include "libs/controllers/CClient.h"

/**
 * @brief The CJanus class represents Selex Janus device.
 *
 * @details Janus FF system consists of a Panoramic Sensor Unit (PSU), an electronics unit (EU) and a different set of cables.
 * The PSU in mainly composed of a cluster of Day-Night vision sensors and a LRF integrated into a viewing platform
 * stabilized on two axes: to refine the performance of image stabilization, the reidue resulting from the electromechanical
 * stabilization process is further reduced through a process of electronic stabilization.
 * The Janus system allows for observation, description, and tracking of ground targets and aircraft.
 */
class CServer : public QTcpServer {

		Q_OBJECT

	public:
		explicit CServer(QObject *parent = 0);
		~CServer();

		/**
		 * @brief Method called to start server
		 */
		void Run();

		CClient *GetClient() const;


	public slots:
		/**
		 * @brief Slot called when new incoming connection come
		 */
		void IncomingConnection();

	signals:
		void CreateClient();
		void MessageStatus(const char* aMessage, int aTimeMsc);

	private:
		CClient *mClient;
};

#endif // CSERVER_H
