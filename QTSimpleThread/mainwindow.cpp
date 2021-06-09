#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    pool = new QThreadPool(this);
    pool->setMaxThreadCount(MAX_THREAD_COUNT);


    th = new ThreadNoSimple[10];
    simpleT = new QSimpleThread();
    connect(ui->buttonThreadSpawner, &QPushButton::clicked, this, &MainWindow::StartThreadPoolThread);
    connect(ui->ThreadButton, &QPushButton::clicked, this, &MainWindow::StartThread);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartThreadPoolThread()
{
    QThreadPool::globalInstance()->start(simpleT);
}

void MainWindow::StartThread()
{
    if(nTask < MAX_THREAD_COUNT)
    {
        th[nTask].passData(nTask); //I thread li ho gia creati
        (th[nTask++]).start();
    }
    //QThreadPool::globalInstance()->start(simpleT);
}



