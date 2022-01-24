#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&m_object,SIGNAL(transmit_to_gui(bool)),this,SLOT(receive_from_object(bool)));

    connect(this,SIGNAL(transmit_to_object(bool)),&m_object,SLOT(receive_from_gui(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


object::object(QObject *parent)
{

}

void object::receive_from_gui(bool value)
{
    state = value;

    emit transmit_to_gui(state);
}

void MainWindow::receive_from_object(bool value)
{
    if(value)
    {
        ui->lineEdit->setText("true");
    }
    else
    {
        ui->lineEdit->setText("false");
    }
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        emit transmit_to_object(true);
    }
    else
    {
        emit transmit_to_object(false);
    }

}
