#include "udpmessage.h"

UdpMessage::UdpMessage(QObject *parent): QObject(parent)
{

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 1234);

    connect(socket, &QUdpSocket::readyRead, this, &UdpMessage::Received);
}


void UdpMessage::Received()
{
  QByteArray buffer;
  buffer.resize(socket->pendingDatagramSize());
  QHostAddress sender;
  quint16 senderPort;

  socket->readDatagram(buffer.data(), buffer.size(),&sender, &senderPort);

  qDebug() << "Message from: " << sender.toString();
  qDebug() << "Message port: " << senderPort;
  qDebug() << "Message: " << buffer;
}

void UdpMessage::MsgUdp()
{
    QByteArray Data;
    Data.append("Hello from UDP");

    // Sends the datagram datagram
    // to the host address and at port.
    // qint64 QUdpSocket::writeDatagram(const QByteArray & datagram,
    //                      const QHostAddress & host, quint16 port)
    socket->writeDatagram(Data, QHostAddress::LocalHost, 1234);
}