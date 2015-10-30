#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QMainWindow>

#include "libs/controllers/IServer.h"
#include "libs/controllers/CServer.h"
#include "libs/controllers/CSettings.h"
#include "libs/dao/CRepository.h"

namespace Ui {
class MainWindow;
}

class CMainWindow : public QMainWindow {
    Q_OBJECT

  public:
    /**
    * @brief MainWindow constructor
    */
    explicit CMainWindow(QWidget *aParent = 0);

    /**
    * @brief MainWindow destructor
    */
    ~CMainWindow();

    /**
     * @brief Method connect to database one more time
     *
     * @return True if connection success, False if is unable to
     *				 connect to specify database
     */
    bool ConnectToDatabaseAgain();

  private slots:
    /**
     * @brief DisplayData is slot to Display data in main window.
     *
     * @param aData is data to show
     */
    void DisplayData(QByteArray aData);

    /**
     * @brief ClientConnected slot is call when server emited signal
     *				incoming connection. This method connect client signal
     *				ReadData to send data to CMainWindow
     */
    void ClientConnected();

    /**
     * @brief ClientCreated slot is call when client was created
     */
    void ClientCreated();

    /**
     * @brief ShowStatus
     *
     * @param aMessageStatus
     * @param aTimeMsc
     */
    void ShowStatus(const char *aMessageStatus, int aTimeMsc);

    /**
     * @brief RunServer slot is call to run server. Start listening
     *				on specify port. Default is 1234
     */
    void RunServer();

    /**
     * @brief StopServer method stop listening on specify port
     */
    void StopServer();

    /**
     * @brief ServerSettings display form to manage server
     */
    void ServerSettings();

    /**
     * @brief DatabaseConnectionSettings slot display form to
     *				change database connection options
     */
    void DatabaseConnectionSettings();

    /**
     * @brief ChangeActionServerStatus method enable buttons
     *				which should be active and disable non active
     */
    void ChangeActionServerStatus();

    /**
    * @brief Close Application event communicate with user and question if
    *				 we really sure to close application
    *
    * @todo finally turn on
    */
    void closeEvent(QCloseEvent *aEvent);

  private:
    /**
     * @brief Method connect server signals to CMainWindow slots
     */
    inline void ConnectServerSignals();

    /**
     * @brief Method connect signals represents actions
     *			  to CMainWindow slots
     */
    inline void ConnectActionsSignals();

    Ui::MainWindow *ui;
		IServer *mServer;
};

#endif // MAINWINDOW_H
