#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
  /* *****************************************************************
   * quando un oggetto viene generato tramite interfaccia grafica,
   * viene caricato dal costruttore dell'oggetto MainWindow, col metodo
   * setupUI
   * ***************************************************************** */

  ui->setupUi(this);

  QString labelButtonDynamic = "Dynamic Button";
  m_buttonDynamic = new QPushButton(labelButtonDynamic, this); //Premi F1 per scoprire cosa fanno.
  m_buttonDynamic->setGeometry(QRect(450, 490, 100, 50));

  QObject::connect( ui->pushButton, &QPushButton::released, this, &MainWindow::Handlebutton);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::Handlebutton() // questo metodo dovrebbe essere generico che gestisce i tasti.
{
  m_dialogColorSelection = new ColorSelection(this);
}
