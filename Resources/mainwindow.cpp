#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QImage>
#include <mainwindow.h>
#include <QMouseEvent>

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
    buttonStdDialogModaless->show();
    QString labelImgButton = "Image Dialog";
    buttonImgDialog = new QPushButton(labelImgButton, this);
    buttonImgDialog->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN*4, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);
    QString labelImgButtonExec = "Image Dialog Exec";
    buttonImgDialogExec = new QPushButton(labelImgButtonExec, this);
    buttonImgDialogExec->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN*5, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);


    connect(buttonColorDialog, &QPushButton::pressed, this, &MainWindow::ColorDialogOpener);
    connect(buttonStdDialogModal, &QPushButton::pressed, this, &MainWindow::StdDialogOpenerModal);
    connect(buttonStdDialogModaless, &QPushButton::pressed, this, &MainWindow::StdDialogOpenerModeless);
    connect(buttonImgDialog, &QPushButton::pressed, this, &MainWindow::ImageDialog);
    connect(buttonImgDialogExec, &QPushButton::pressed, this, &MainWindow::ImageDialogExec);

    //connect(this, &MainWindow::mousePressed, this, &MainWindow::mousePressEvent);
    qDebug("Fine inizializzazione MainWindow");

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
    imgDialog->setAttribute(Qt::WA_DeleteOnClose); //libera la memoria ogni volta che viene chiuso.

    QPixmap *imagePix = new QPixmap(":/map"); //utilizzo l'alias
    QLabel *imageLabel = new QLabel(imgDialog); //FONDAMENTALE, attacca la label all'interfaccia

    imageLabel->setPixmap((*imagePix).scaled(this->width(),this->height(),Qt::IgnoreAspectRatio));

    imgDialog->show();


    QString labelImgButton = "Image Dialog Btn";
    buttonInImgDialog = new QPushButton(labelImgButton, imageLabel);
    buttonInImgDialog->setGeometry(0, imgDialog->geometry().height() - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);
    buttonInImgDialog->show();

    connect(buttonInImgDialog, &QPushButton::clicked, this, &MainWindow::CloseDialogImage);
}

void MainWindow::ImageDialogExec()
{
    imgDialog = new QDialog(this);

    imgDialog->setGeometry(this->geometry().x(),this->geometry().y(),this->width(), this->height());
    imgDialog->setAttribute(Qt::WA_DeleteOnClose); //libera la memoria ogni volta che viene chiuso.

    QPixmap *imagePix = new QPixmap(":/geometry"); //utilizzo l'alias
    QLabel *imageLabel = new QLabel(imgDialog); //FONDAMENTALE, attacca la label all'interfaccia

    imageLabel->setPixmap((*imagePix).scaled(this->width(),this->height(),Qt::IgnoreAspectRatio));

    QString labelImgButton = "Image Dialog Btn";
    buttonInImgDialog = new QPushButton(labelImgButton, imageLabel);
    buttonInImgDialog->setGeometry(0, imgDialog->geometry().height() - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);
    buttonInImgDialog->show();

    connect(buttonInImgDialog, &QPushButton::clicked, this, &MainWindow::CloseDialogImage);


    imgDialog->exec();  //The most common way to display a modal dialog is to call its exec() function
    //Attenzione che questo exec prende il "potere" su tutta la gestione dei thread della cpu
    //per me era meglio, //imgDialog->setModal(true); fare imgDialog->show() e
}

void MainWindow::CloseDialogImage()
{
    this->imgDialog->close();
}

void MainWindow::mousePressEvent( QMouseEvent* ev )
{
    qDebug("Hai premuto un tasto nella main windows?");
    const QPoint p = ev->pos();
    emit mousePressed( p );
}
