#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QMainWindow>

#include "src/libs/controllers/IServer.h"
#include "src/libs/controllers/CServer.h"
#include "src/libs/controllers/CSettings.h"
#include "src/libs/dao/CRepository.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief The CMainWindow class
 */
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
     *		   connect to specify database
     */
    bool ConnectToDatabaseAgain();

	protected slots:
    /**
     * @brief DisplayData is slot to Display data in main window.
     *
     * @param aData is data to show
     */
    void DisplayData(QByteArray aData);

    /**
     * @brief ClientConnected slot is call when server emited signal
     *	      incoming connection. This method connect client signal
     *		  ReadData to send data to CMainWindow
     */
    void ClientConnected();

    /**
     * @brief ReceiverCreated slot is call when client was created
     */
    void ReceiverCreated();

    /**
     * @brief Increment current photo number
     */
    void IncrementCurrentPhotoNumber();

    /**
     * @brief ShowStatus
     *
     * @param aMessageStatus
     * @param aTimeMsc
     */
    void ShowStatus(const char *aMessageStatus, int aTimeMsc);

    /**
     * @brief RunServer slot is call to run server. Start listening
     *		  on specify port. Default is 1234
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
     * @brief AboutProgram slot display form  with information about program
     */
    void AboutProgram();

    /**
     * @brief DatabaseConnectionSettings slot display form to
     *		  change database connection options
     */
    void DatabaseConnectionSettings();

    /**
     * @brief ChangeActionServerStatus method enable buttons
     *		  which should be active and disable non active
     */
    void ChangeActionServerStatus();

    /**
    * @brief Close Application event communicate with user and question if
    *		 we really sure to close application
    *
    * @todo finally turn on
    */
    void closeEvent(QCloseEvent *aEvent);

private slots:
    //TODO
    void on_mPushButtonPrevious_clicked();
    void on_mPushButtonNext_clicked();

	protected:
    /**
     * @brief UpdateDatabaseOrConnection if database exists populate database,
     *        otherwise open DatabaseConnectionSettings dialog
     *
     * @return True if database exists, otherwise false
     */
    bool UpdateDatabaseOrConnection();

    /**
     * @brief TryRunServer Try call RunServer method. Throw exception if server listening
     *        problem occured
     */
    void TryRunServer();

    /**
     * @brief IsDatabase Verify if database exist, if it is not null pointer
     *
     * @return True if database exists, otherwise false
     */
    bool IsDatabase();

    /**
     * @brief ServerListeningProblem attend server listening exception
     *
     * @param aError server error
     */
    void ServerListeningProblem(const char *aError);

    /**
     * @brief Method connect server signals to CMainWindow slots
     */
    inline void ConnectServerSignals();

    /**
     * @brief Method connect signals represents actions
     *		  to CMainWindow slots
     */
    inline void ConnectActionsSignals();

    /**
     * @brief ui Pointer to user interface
     */
    Ui::MainWindow *ui;

    /**
     * @brief mServer Pointer to server
     */
    IServer *mServer;

    /**
     * @brief mCurrentPhoto Current photo
     */
    int mCurrentPhoto;

};

#endif // MAINWINDOW_H
