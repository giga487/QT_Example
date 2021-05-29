#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDialog>
#include "DialogGeometry.h"
#include "QTcpSocket"

class Client: public QDialog
{
    Q_OBJECT
  public:
    Client(QWidget *parent = nullptr);
    void StartClientConnection();

  private:
    QTcpSocket *m_socket = nullptr;
    QDataStream in;
};

#endif // CLIENT_H
