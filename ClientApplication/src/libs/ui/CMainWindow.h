#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

#include "src/libs/controllers/CClient.h"
#include "src/libs/controllers/IClient.h"

namespace Ui {
class CMainWindow;
}

/**
 * @brief The CMainWindow class is the interface of
 *        Client application
 */
class CMainWindow : public QMainWindow {
    Q_OBJECT

  public:
    /**
     * @brief CMainWindow class constructor
     * @param aParent is parent
     */
    explicit CMainWindow(QWidget *aParent = 0);

    /**
     *@brief CMainWindow class destructor
     */
    ~CMainWindow();

	protected slots:
    /**
     * @brief on_mPushButtonSendPhoto_clicked
     */
    void on_mPushButtonSendPhoto_clicked();
    void on_mPushButtonSendChecksum_clicked();
    void on_mPushButtonConnect_clicked();

    /**
     * @brief on_mPushButtonArchivePhoto_clicked slot when
     *        need archivize photos
     */
    void on_mPushButtonArchivePhoto_clicked();

	protected:
		/**
		 * @brief ShowSocketException Comunicate socket exception
		 * @param vError Socket error
		 */
		void ShowSocketException(QAbstractSocket::SocketError aError);

    /**
     * @brief ui Is dialog
     */
    Ui::CMainWindow *ui;

    /**
     * @brief vClient is Client class
     */
    IClient *vClient;
};

#endif // CMAINWINDOW_H
