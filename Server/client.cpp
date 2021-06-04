#include "client.h"

//Inizializzo un nuovo socket quando parte il costruttore
//questo serve per evitare che il costruttore venga costruito prima del padre.
Client::Client(QWidget *parent): QDialog(parent), m_socket(new QTcpSocket(this)), m_port(60000)
{

    m_socket = new QTcpSocket(parent);
    m_socket->connectToHost(QHostAddress::LocalHost, m_port);

    in.setDevice(m_socket);
    in.setByteOrder(QDataStream::BigEndian);

    msg = new MSG_KEEP_ALIVE();

    connect(m_socket, &QTcpSocket::connected, this, &Client::Connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::ReadData);

    m_socket->waitForConnected();
}

QDataStream &operator>>(QDataStream &stream, MSG_KEEP_ALIVE *msg)
{
    stream >> msg->Header.TipoMessaggio  >> msg->Header.Sender >> msg->Header.Lunghezza >> msg->Header.Contatore;
    //qDebug("RX: ID %d, S %d, L %d, Count %d",  msg->Header.TipoMessaggio,  msg->Header.Sender,  msg->Header.Lunghezza,  msg->Header.Contatore );
    return stream;
}


void Client::ReadData()
{
    QBitArray keepAlive(8);
    //memset(&un.ch, 0, 5);
    //memcpy(&un.ch, m_socket->readAll(), 5);
    in >> msg >> keepAlive;
    //viene impacchettato in modo corretto anche se non me lo sarei aspettato
    char buff;

    memcpy(&buff, &keepAlive, 1 );
    // |3 | 2 | 0 16 | 0000
    //qDebug("MSG[%d] ID: %d, S: %d,  L %d, C: %d", mxRx++, un.msg_t.Header.TipoMessaggio, un.msg_t.Header.Sender, un.msg_t.Header.Lunghezza,  un.msg_t.Header.Contatore );
    qDebug("MSG[%d] ID: %d, S: %d,  L %d, C: %d, MSG %u", mxRx++, msg->Header.TipoMessaggio, msg->Header.Sender, msg->Header.Lunghezza,  msg->Header.Contatore, buff );

}

void Client::Connected()
{
    qDebug("Connected at %d", m_port);
}




