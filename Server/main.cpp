#include "mainwindow.h"
#include "udpmessage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);



  MainWindow w;
  w.show();
  return a.exec();
}


