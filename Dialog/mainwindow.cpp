#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString labelButton = "ColorGump";
    buttonColorDialog = new QPushButton(labelButton, this);
    buttonColorDialog->setGeometry(WIDTH_MAIN - WIDTH_COLOR_BTN, HEIGTH_MAIN - HEIGHT_COLOR_BTN, WIDTH_COLOR_BTN,HEIGHT_COLOR_BTN);

    connect(buttonColorDialog, &QPushButton::pressed, this, &MainWindow::ColorDialogOpener);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ColorDialogOpener()
{
    qDebug("CI SIAMO");
    QColor color = QColorDialog::getColor(Qt::green, this, "Select Color");

    if (color.isValid()) {
        buttonColorDialog->setPalette(QPalette(color));
        buttonColorDialog->setAutoFillBackground(true);
        buttonColorDialog->update();
    }


}
