#include "client.h"

//Inizializzo un nuovo socket quando parte il costruttore
//questo serve per evitare che il costruttore venga costruito prima del padre.
Client::Client(QWidget *parent): QDialog(parent), m_socket(new QTcpSocket(this)), m_port(60000)
{
    m_socket = new QTcpSocket(parent);
    m_socket->connectToHost(QHostAddress::LocalHost, m_port);

    in.setDevice(m_socket);
    in.setVersion(QDataStream::Qt_6_0);
    in.setByteOrder(QDataStream::BigEndian);

    connect(m_socket, &QTcpSocket::connected, this, &Client::Connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::ReadData);

    m_socket->waitForConnected();
}

void Client::ReadData()
{


    memset(&bufferH, 0, sizeof(MSG_HEADER));

    memcpy(&bufferH, m_socket->readAll(), 8);

    memcpy(&head, &bufferH, 8);

    // |3 | 2 | 0 16 | 0000
    qDebug("MSG[%d] ID: %d, S: %d,  L %d, C: %d", mxRx++, head.TipoMessaggio, head.Sender, head.Lunghezza,  head.Contatore );

}

void Client::Connected()
{
    qDebug("Connected at %d", m_port);
}




