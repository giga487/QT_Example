#include "mainwindow.h"
#include <QSplitter>
#include <QSplitterHandle>
#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplitter *splitter = new QSplitter;

    QFileSystemModel *model = new QFileSystemModel; //#include <QFileSystemModel>
    model->setRootPath(QDir::currentPath());

    QTreeView *tree = new QTreeView(splitter); //Cosa è un qsplitter?
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));
    splitter->setWindowTitle("Two views onto the same file system model");
    splitter->show();

    MainWindow w;
    w.show();
    return a.exec();
}
