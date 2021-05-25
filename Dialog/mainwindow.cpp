#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString labelColorButton = "Color";
    buttonColorDialog = new QPushButton(labelColorButton, this);
    buttonColorDialog->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);
    QString labelCustomButton = "Custom Dialog";
    buttonCustomDialog = new QPushButton(labelCustomButton, this);
    buttonCustomDialog->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN*2, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);

    connect(buttonColorDialog, &QPushButton::pressed, this, &MainWindow::ColorDialogOpener);
    connect(buttonCustomDialog, &QPushButton::pressed, this, &MainWindow::CustomDialogOpener);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ColorDialogOpener()
{
    qDebug("Ok, colored");
    QColor color = QColorDialog::getColor(Qt::green, this, "Select Color");

    if (color.isValid()) {
        buttonColorDialog->setPalette(QPalette(color));
        buttonColorDialog->setAutoFillBackground(true);
        buttonColorDialog->update();
    }
}

void MainWindow::CustomDialogOpener()
{
  qDebug("Ok, custom dialog");
  customDialog = new CustomDialog(this);
}
