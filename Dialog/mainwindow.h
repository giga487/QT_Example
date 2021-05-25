#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

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
private:
    Ui::MainWindow *ui;
    QPushButton *buttonColorDialog;
};
#endif // MAINWINDOW_H
