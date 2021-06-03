#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDialog>
#include "DialogGeometry.h"
#include "QTcpSocket"
#include <QtNetwork>
#include <encoderComm.h>

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
    QByteArray rxBuffer;
    MSG_UNION un;
    int mxRx = 0;


};

#endif // CLIENT_H
