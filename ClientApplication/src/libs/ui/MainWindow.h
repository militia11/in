#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

#include "src/libs/controllers/CClient.h"

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
   *
   * @param aParent is parent
   */
  explicit CMainWindow(QWidget *aParent = 0);

  /**
   *@brief CMainWindow class destructor
   */
  ~CMainWindow();

 protected slots:
  /**
   * @brief Show status
   *
   * @param aMessage Message
   */
  void ShowStatus(QString aMessage);

  /**
   * @brief on_mPushButtonConnect_clicked
   */
  void on_mPushButtonConnect_clicked();

  /**
   * @brief on_mPushButtonArchivePhoto_clicked slot when
   *        need archivize photos
   */
  void on_mPushButtonArchivePhoto_clicked();

  /**
   * @brief on_mArchivizeInServer_clicked
   */
  void on_mArchivizeInServer_clicked();

  /**
   * @brief on_mPhotos_clicked
   *
   * @param index Index
   */
  void on_mPhotos_clicked(const QModelIndex &index);

  /**
   * @brief on_mPhotos_doubleClicked
   *
   * @param index Index
   */
  void on_mPhotos_doubleClicked(const QModelIndex &index);

 protected:
  /**
   * @brief Populate pictures list
   */
  void populatePicturesList();

  /**
   * @brief ShowSocketException Comunicate socket exception
   *
   * @param vError Socket error
   */
  void ShowSocketException(QAbstractSocket::SocketError aError);

  /**
   * @brief ui User interface dialog
   */
  Ui::CMainWindow *ui;

  /**
   * @brief vClient Client class
   */
  CClient *mClient;
};

#endif // CMAINWINDOW_H
