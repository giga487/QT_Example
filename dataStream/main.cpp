#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QDataStream *in;



  //QFile file("D:\\Git\\QT_Example\\dataStream\\img.jpg");
  QFile file("E:\\Lavoro\\Git\\QT_Example\\dataStream\\img.jpg");

  if(file.exists() == true)
  {
    file.open(QIODevice::ReadOnly);
    qDebug("File aperto");
  }


  in = new QDataStream(&file);   // we will serialize the data into the file
  in->setByteOrder(QDataStream::LittleEndian);

  qDebug() << "Data" << in->device()->pos();
  qDebug() << "data content after write: " << file.readAll();

  in->device()->seek(0); // mi posiziono sull'elemento zero
  qDebug() << "Device pos after seek: " << in->device()->pos();

  w.show();
  return a.exec();
}
