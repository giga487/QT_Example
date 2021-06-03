#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <server.h>
#include <client.h>
#include "udpmessage.h"


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
    void SendUdp();
  private:
    Ui::MainWindow *ui;
    ServerEnc *server = nullptr;
    Client *client = nullptr;
    UdpMessage *udpM = nullptr;

};
#endif // MAINWINDOW_H
