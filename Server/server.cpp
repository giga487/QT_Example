#include "server.h"

/* questa classe istanzia il server tcp/udp e attende la comunicazione */
Server::Server(QWidget *parent)
{
 // int pos = parent->geometry
  qDebug("Creazione del socket Tcp lato Server");


  m_server = new QTcpServer(this);

  QString ipAddress;
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

  for (int i = 0; i < ipAddressesList.size(); ++i)
  {
      if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address())
      {
          ipAddress = ipAddressesList.at(i).toString();
          break;
      }
  }

  if (ipAddress.isEmpty())
         ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

  this->setWindowTitle("Server");
  this->setGeometry(parent->geometry().x() + parent->width(), parent->geometry().y(), SERVER_DIALOG_WIDTH, SERVER_DIALOG_HEIGHT);
  this->setModal(false);
  this->show();
  this->activateWindow();

  connect(m_server, &QTcpServer::newConnection, this, &Server::ReceivedComm);

}

Server::~Server()
{

}

void Server::ReceivedComm()
{

}
