#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "colorselection.h"

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
    void Handlebutton();
  private:
    Ui::MainWindow *ui;
    QPushButton *m_buttonDynamic;
    ColorSelection *m_dialogColorSelection;
    void OpenModalDialog();
    void OpenModelessDialog();
    QColor m_colorApp;

};
#endif // MAINWINDOW_H
