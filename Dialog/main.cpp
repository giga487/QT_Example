#include "mainwindow.h"

#include <QApplication>
#include <QColorDialog>


/* In questo esempio, viene mostrato un color dialog ed un custom dialog */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
