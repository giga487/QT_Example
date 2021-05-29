#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QImage>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString labelColorButton = "Color";
    buttonColorDialog = new QPushButton(labelColorButton, this);
    buttonColorDialog->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);
    QString labelDialogButtonModal = "Modal Dialog";
    buttonStdDialogModal = new QPushButton(labelDialogButtonModal, this);
    buttonStdDialogModal->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN*2, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);

    QString labelDialogButtonModeless = "Modeless Dialog";
    buttonStdDialogModaless = new QPushButton(labelDialogButtonModeless, this);
    buttonStdDialogModaless->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN*3, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);

    QString labelImgButton = "Image Dialog";
    buttonImgDialog = new QPushButton(labelImgButton, this);
    buttonImgDialog->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN*4, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);

    connect(buttonColorDialog, &QPushButton::pressed, this, &MainWindow::ColorDialogOpener);
    connect(buttonStdDialogModal, &QPushButton::pressed, this, &MainWindow::StdDialogOpenerModal);
    connect(buttonStdDialogModaless, &QPushButton::pressed, this, &MainWindow::StdDialogOpenerModeless);
    connect(buttonImgDialog, &QPushButton::pressed, this, &MainWindow::ImageDialog);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ColorDialogOpener()
{
    qDebug("Ok, colored");
    QColor color = QColorDialog::getColor(Qt::green, this, "Select Color");

    if (color.isValid())
    {
        buttonColorDialog->setPalette(QPalette(color));
        buttonColorDialog->setAutoFillBackground(true);
        buttonColorDialog->update();
    }
}

void MainWindow::StdDialogOpenerModal()
{
  qDebug("Ok, custom dialog");
  stdDialogModal = new CustomDialog(this, true, "Modal");

  //stdDialog = new QDialog();
  //stdDialog->setModal(true);
  //stdDialog->show();

}

void MainWindow::StdDialogOpenerModeless()
{
  qDebug("Ok, custom dialog");
  stdDialogModeless = new CustomDialog(this, false, "Modeless");
  //stdDialog = new QDialog();
  //stdDialog->setModal(true);
  //stdDialog->show();
}

void MainWindow::ImageDialog()
{
  imgDialog = new QDialog(this);
  imgDialog->setGeometry(this->geometry().x(),this->geometry().y(),this->width(), this->height());

  QPixmap *imagePix = new QPixmap(":/map");
  QLabel *imageLabel = new QLabel(imgDialog); //FONDAMENTALE, attacca la label all'interfaccia

  imageLabel->setPixmap((*imagePix).scaled(this->width(),this->height(),Qt::IgnoreAspectRatio));

  imgDialog->show();
  //imageLabel->setPixmap();

}
