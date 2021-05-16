#include "mainwindow.h"

#include <QApplication>
#include <Counter.h>
#include <QDebug>

//https://woboq.com/blog/how-qt-signals-slots-work.html

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Counter c1,c2;

  QObject::connect(&c1, &Counter::valueChanged, &c2, &Counter::setValue);

  c1.setValue(100);
  qDebug("Value %d", c2.getValue());

  MainWindow w;
  w.show();
  return a.exec();
}
