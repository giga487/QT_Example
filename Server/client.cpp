#include "client.h"

//Inizializzo un nuovo socket quando parte il costruttore
//questo serve per evitare che il costruttore venga costruito prima del padre.
Client::Client(QWidget *parent): QDialog(parent), m_socket(new QTcpSocket(this))
{
  this->setWindowTitle("Client");
  this->setGeometry(parent->geometry().x()+parent->width(), parent->pos().y()-CLIENT_DIALOG_HEIGHT, CLIENT_DIALOG_WIDTH, CLIENT_DIALOG_HEIGHT);
  this->show();
  this->activateWindow();
}






