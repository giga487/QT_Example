#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include "customdialog.h"
#include <QDialog>

#define WIDTH_MAIN 800
#define HEIGTH_MAIN 600
#define WIDTH_COLOR_BTN 100
#define HEIGHT_COLOR_BTN 100

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ColorDialogOpener();
    void StdDialogOpenerModal();
    void StdDialogOpenerModeless();
    void ImageDialog();
    void ImageDialogExec();
    void mousePressEvent( QMouseEvent* ev ) override;
    void CloseDialogImage();

signals:
    void mousePressed( const QPoint&);

private:
    Ui::MainWindow *ui;
    QPushButton *buttonColorDialog;
    QPushButton *buttonStdDialogModal;
    QPushButton *buttonStdDialogModaless;
    QPushButton *buttonImgDialog;
    CustomDialog *customDialog;
    QDialog *stdDialogModal;
    QDialog *stdDialogModeless;
    QDialog *imgDialog;
    QDialog *imgDialogExec;
    QPushButton *buttonImgDialogExec;
    QPushButton *buttonInImgDialog;
};
#endif // MAINWINDOW_H
