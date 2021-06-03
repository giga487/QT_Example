#include "client.h"

//Inizializzo un nuovo socket quando parte il costruttore
//questo serve per evitare che il costruttore venga costruito prima del padre.
Client::Client(QWidget *parent): QDialog(parent), m_socket(new QTcpSocket(this)), m_port(60000)
{
    m_socket = new QTcpSocket(parent);
    m_socket->connectToHost(QHostAddress::LocalHost, m_port);

    connect(m_socket, &QTcpSocket::connected, this, &Client::Connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::ReadData);

    m_socket->waitForConnected();
}

void Client::ReadData()
{
    memset(&un.ch, 0, 5);
    memcpy(&un.ch, m_socket->readAll(), 5);

    // |3 | 2 | 0 16 | 0000
    qDebug("MSG[%d] ID: %d, S: %d,  L %d, C: %d", mxRx++, un.msg_t.Header.TipoMessaggio, un.msg_t.Header.Sender, un.msg_t.Header.Lunghezza,  un.msg_t.Header.Contatore );

}

void Client::Connected()
{
    qDebug("Connected at %d", m_port);
}




