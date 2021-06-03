#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DialogGeometry.h"
#include "server.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpM = new UdpMessage();
    connect(ui->serverButton, &QPushButton::clicked, this, &MainWindow::StartServer);
    connect(ui->clientButton, &QPushButton::clicked, this, &MainWindow::StartClient);
    connect(ui->udpButton, &QPushButton::clicked, this, &MainWindow::SendUdp);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::StartServer()
{
  server = new ServerEnc(this);
}

void MainWindow::StartClient()
{
  client = new Client(this);
}

void MainWindow::SendUdp()
{

  udpM->MsgUdp();
}
