#include "client.h"

//Inizializzo un nuovo socket quando parte il costruttore
//questo serve per evitare che il costruttore venga costruito prima del padre.
Client::Client(QWidget *parent): QDialog(parent), m_socket(new QTcpSocket(this)), m_port(60000)
{
    m_socket = new QTcpSocket(parent);
    m_socket->connectToHost(QHostAddress::LocalHost, m_port);

    in.setDevice(m_socket);
    in.setVersion(QDataStream::Qt_4_0);

    connect(m_socket, &QTcpSocket::connected, this, &Client::Connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::ReadData);



    m_socket->waitForConnected();
}

void Client::ReadData()
{
    /*
    in.startTransaction();

    QString nextFortune;
    in >> nextFortune;

    if(!in.commitTransaction())
    {
        qDebug("Errore");
        return;
    }

    qDebug() << nextFortune;
    */
    qDebug() << m_socket->readAll();
}

void Client::Connected()
{
    qDebug("Connected at %d", m_port);
}




