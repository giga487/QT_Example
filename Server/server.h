#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QDialog>
#include "DialogGeometry.h"
#include <QMessageBox>
#include <QtNetwork>


class Server: QWidget
{
    Q_OBJECT
  public:
    Server(QWidget *parent = nullptr);
    ~Server();
  public slots:
    void ReceivedComm();
  private:
    QDialog *m_dialog = nullptr;
    QTcpServer *m_server = nullptr;


};

#endif // SERVER_H
