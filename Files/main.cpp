#include "mainwindow.h"

#include <QApplication>
#include <QFileInfo>


int main(int argc, char *argv[])
{
  QTextStream out{stdout};

  QString filename = "img.jpg";

  QFile f(filename);

  if (!f.exists())
  {

    qWarning("The file does not exist");
    return 1;
  }

  QFileInfo fileinfo{filename};

  qint64 size = fileinfo.size();

  QString str = "The size is: %1 bytes";

  out << str.arg(size);

  return 0;
}
