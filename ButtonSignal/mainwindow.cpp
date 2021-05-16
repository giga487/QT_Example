#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *pButton = ui->m_pushButtonNum;

    //connect(pButton, &QPushButton::released, this, &MainWindow::WriteText()); //Function Pointer

}

void MainWindow::WriteText()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

