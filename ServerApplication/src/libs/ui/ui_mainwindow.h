/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ActionRunServer;
    QAction *ActionCloseEvent;
    QAction *ActionDataBaseConnection;
    QAction *ActionServerSettings;
    QAction *ActionStopServer;
    QWidget *mentralwidget;
    QTextEdit *mTextEdit;
    QListWidget *mListWidget;
    QLabel *mImageLabel;
    QMenuBar *mMenubar;
    QMenu *menuPlik;
    QMenu *menuUstawienia;
    QMenu *menuSerwer;
    QStatusBar *mStatusbar;
    QToolBar *mToolBarServer;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(622, 549);
        ActionRunServer = new QAction(MainWindow);
        ActionRunServer->setObjectName(QStringLiteral("ActionRunServer"));
        ActionRunServer->setCheckable(true);
        ActionCloseEvent = new QAction(MainWindow);
        ActionCloseEvent->setObjectName(QStringLiteral("ActionCloseEvent"));
        ActionDataBaseConnection = new QAction(MainWindow);
        ActionDataBaseConnection->setObjectName(QStringLiteral("ActionDataBaseConnection"));
        ActionServerSettings = new QAction(MainWindow);
        ActionServerSettings->setObjectName(QStringLiteral("ActionServerSettings"));
        ActionStopServer = new QAction(MainWindow);
        ActionStopServer->setObjectName(QStringLiteral("ActionStopServer"));
        ActionStopServer->setCheckable(true);
        mentralwidget = new QWidget(MainWindow);
        mentralwidget->setObjectName(QStringLiteral("mentralwidget"));
        mTextEdit = new QTextEdit(mentralwidget);
        mTextEdit->setObjectName(QStringLiteral("mTextEdit"));
        mTextEdit->setGeometry(QRect(350, 20, 201, 121));
        mListWidget = new QListWidget(mentralwidget);
        mListWidget->setObjectName(QStringLiteral("mListWidget"));
        mListWidget->setGeometry(QRect(10, 20, 321, 121));
        mImageLabel = new QLabel(mentralwidget);
        mImageLabel->setObjectName(QStringLiteral("mImageLabel"));
        mImageLabel->setGeometry(QRect(16, 156, 531, 261));
        mImageLabel->setScaledContents(true);
        MainWindow->setCentralWidget(mentralwidget);
        mMenubar = new QMenuBar(MainWindow);
        mMenubar->setObjectName(QStringLiteral("mMenubar"));
        mMenubar->setGeometry(QRect(0, 0, 622, 25));
        menuPlik = new QMenu(mMenubar);
        menuPlik->setObjectName(QStringLiteral("menuPlik"));
        menuUstawienia = new QMenu(mMenubar);
        menuUstawienia->setObjectName(QStringLiteral("menuUstawienia"));
        menuSerwer = new QMenu(mMenubar);
        menuSerwer->setObjectName(QStringLiteral("menuSerwer"));
        MainWindow->setMenuBar(mMenubar);
        mStatusbar = new QStatusBar(MainWindow);
        mStatusbar->setObjectName(QStringLiteral("mStatusbar"));
        MainWindow->setStatusBar(mStatusbar);
        mToolBarServer = new QToolBar(MainWindow);
        mToolBarServer->setObjectName(QStringLiteral("mToolBarServer"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mToolBarServer);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        mMenubar->addAction(menuPlik->menuAction());
        mMenubar->addAction(menuSerwer->menuAction());
        mMenubar->addAction(menuUstawienia->menuAction());
        menuPlik->addSeparator();
        menuPlik->addAction(ActionCloseEvent);
        menuUstawienia->addAction(ActionDataBaseConnection);
        menuSerwer->addAction(ActionRunServer);
        menuSerwer->addAction(ActionStopServer);
        menuSerwer->addSeparator();
        menuSerwer->addAction(ActionServerSettings);
        mToolBarServer->addAction(ActionRunServer);
        mToolBarServer->addAction(ActionStopServer);

        retranslateUi(MainWindow);
        QObject::connect(ActionCloseEvent, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Android Synchronizator", 0));
        ActionRunServer->setText(QApplication::translate("MainWindow", "Start serwer", 0));
#ifndef QT_NO_TOOLTIP
        ActionRunServer->setToolTip(QApplication::translate("MainWindow", "Prze\305\202\304\205cz serwer w tryb nas\305\202uchiwania", 0));
#endif // QT_NO_TOOLTIP
        ActionRunServer->setShortcut(QApplication::translate("MainWindow", "Shift+N", 0));
        ActionCloseEvent->setText(QApplication::translate("MainWindow", "Zamknij ", 0));
#ifndef QT_NO_TOOLTIP
        ActionCloseEvent->setToolTip(QApplication::translate("MainWindow", "Zamknij program", 0));
#endif // QT_NO_TOOLTIP
        ActionCloseEvent->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        ActionDataBaseConnection->setText(QApplication::translate("MainWindow", "Po\305\202\304\205czenie z baz\304\205 danych ", 0));
#ifndef QT_NO_TOOLTIP
        ActionDataBaseConnection->setToolTip(QApplication::translate("MainWindow", "Ustawienie po\305\202\304\205czenia z baz\304\205 danych", 0));
#endif // QT_NO_TOOLTIP
        ActionDataBaseConnection->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0));
        ActionServerSettings->setText(QApplication::translate("MainWindow", "Ustawienia", 0));
#ifndef QT_NO_TOOLTIP
        ActionServerSettings->setToolTip(QApplication::translate("MainWindow", "Ustawienia komunikacji i portu", 0));
#endif // QT_NO_TOOLTIP
        ActionServerSettings->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        ActionStopServer->setText(QApplication::translate("MainWindow", "Stop serwer", 0));
#ifndef QT_NO_TOOLTIP
        ActionStopServer->setToolTip(QApplication::translate("MainWindow", "Zastopuj serwer. Przerwij nas\305\202uchiwanie", 0));
#endif // QT_NO_TOOLTIP
        ActionStopServer->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        mImageLabel->setText(QString());
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", 0));
        menuUstawienia->setTitle(QApplication::translate("MainWindow", "Ustawienia", 0));
        menuSerwer->setTitle(QApplication::translate("MainWindow", "Serwer", 0));
        mToolBarServer->setWindowTitle(QApplication::translate("MainWindow", "Pasek narz\304\231dzi serwer", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
