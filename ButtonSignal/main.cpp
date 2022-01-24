#include "mainwindow.h"

#include <QApplication>
#include "signalButton.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    signalButton *prova = new signalButton();
    prova->setValue();

    signalButton objSignal = signalButton(15);
    objSignal.setValue();

    MainWindow w;
    w.show();
    return a.exec();
}
