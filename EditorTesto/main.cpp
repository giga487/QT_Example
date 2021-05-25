#include "mainwindow.h"

#include <QApplication>
#include <QTableView>
#include "mymodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MyModel myModel; //istance of my model
    tableView.setModel(&myModel); //pass the pointer to tableView.
    tableView.show();
    return a.exec();
}
