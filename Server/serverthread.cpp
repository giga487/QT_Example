#include "serverthread.h"

ServerThread::ServerThread(int socketDescriptor, QObject *parent): QThread(parent), socketDescriptor(socketDescriptor)
{
    qDebug("Server thread init");
}


void ServerThread::run()
{
    QTcpSocket tcpSocket;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setByteOrder(QDataStream::BigEndian);

    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        qDebug("Errore socket Tcp");
    }

    out << "Hello World";

    while(1)
    {
        tcpSocket.write(block);
        tcpSocket.flush();
        //tcpSocket.waitForBytesWritten(3000);

        QThread::msleep(500);
    }

}
