#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QImage>
//#include<QLibraryInfo>
//#include <QObject>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent),
		ui(new Ui::MainWindow) {
		ui->setupUi(this);
		Q_INIT_RESOURCE(resources);

		//QImage vImage = QImage (":/sample_photo.jpeg" "JPEG");
		QPixmap pixmap = QPixmap (":/sample_photo.jpeg");
		//qDebug() << vImage.size();
			ui->label->setPixmap(pixmap);
				//QPixmap::fromImage(vImage));
}

MainWindow::~MainWindow() {
		delete ui;
}
