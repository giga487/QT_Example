#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QDialog>
#include "DialogGeometry.h"
#include <QMessageBox>
#include <QtNetwork>


class Server: QDialog
{
  Q_OBJECT
  public:
    Server(QWidget *parent = nullptr);
    ~Server();
  public slots:
    void StartMessageServer();
    void ReceivedComm();
  private:
    QTcpServer *m_server = nullptr;


};

#endif // SERVER_H
