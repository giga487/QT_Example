#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <server.h>
#include <client.h>

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
    void StartServer();
    void StartClient();
  private:
    Ui::MainWindow *ui;
    Server *m_server = nullptr;
    Client *m_client = nullptr;
};
#endif // MAINWINDOW_H
