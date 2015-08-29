#include "CAddToDBTransaction.h"
#include "libs/dao/CRepository.h"

#include <QImageWriter>
#include <QImageReader>
#include <QImage>
#include <QDebug>
using server::AndroidPhotosDatabase;
using server::Photo;

extern CRepository gRepository;

CAddToDBTransaction::CAddToDBTransaction(QByteArray aData, int aChecksum) :
		mData(aData),
		mChecksum(aChecksum) {
}

void CAddToDBTransaction::Execute() {

		QImage vImage = QImage ("/home/mmichniewski/pies.jpg", "JPG"); // from data load
		QBuffer vBuffer;

		QImageWriter vWriter(&vBuffer, "JPG");
		vWriter.write(vImage);
		 qDebug() << vImage.size() <<"im1";

		QByteArray tab = vBuffer.data();
		qDebug() << tab.size() <<"tab";

		QBuffer buffer(&tab);
		buffer.open( QIODevice::ReadOnly );
		QImageReader reader(&buffer, "JPG");
		QImage image = reader.read();

		qDebug() << image.size() <<"im2";

		server::AndroidPhotosDatabase *mDatabase  = gRepository.GetDatabase();
		Photo vPhoto(*mDatabase);
		vPhoto.checksum = mChecksum; //mChecksum
		std::string stdString(tab.constData(), tab.length());
		vPhoto.data = stdString ;
		//QString temp = QString::number(mData.toInt());
		//const std::string aa = "sas";
		//qDebug() << QString::fromStdString(aa);
		 // temp.toStdString();//.to//imie.toUtf8(); toUtf8().constData();
		vPhoto.update();

		//	model->odswiez();

		//	QSqlQuery qry;
		//	int id;
		//	qry.prepare( "SELECT COUNT(*) FROM images" );
		//	qry.exec();
		//	qry.next();
		//	id = qry.value(0).toInt() + 1;
		//	qry.prepare( "INSERT INTO images (id, data) VALUES (:id, :data)" );
		//	qry.bindValue( ":id", id );
		//	qry.bindValue( ":data", buffer.data() );
		//	qry.exec();
		//	foreach( QString tag, tags )
		//	addTag( id, tag );
}
