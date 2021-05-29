#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DialogGeometry.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);


  connect(ui->serverButton, &QPushButton::clicked, this, &MainWindow::StartServer);
  connect(ui->clientButton, &QPushButton::clicked, this, &MainWindow::StartClient);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::StartServer()
{
  if(m_server == nullptr)
    m_server = new Server(this);
}

void MainWindow::StartClient()
{
  if(m_client == nullptr)
    m_client = new Client(this);
}
