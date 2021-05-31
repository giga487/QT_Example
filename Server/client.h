#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDialog>
#include "DialogGeometry.h"
#include "QTcpSocket"
#include <QtNetwork>

class Client: public QDialog
{
    Q_OBJECT
  public:
    Client(QWidget *parent = nullptr);
    void StartClientConnection();
public slots:
    void ReadData();
    void Connected();
  private:
    QTcpSocket *m_socket = nullptr;
    QDataStream in;
    int m_port;

};

#endif // CLIENT_H
