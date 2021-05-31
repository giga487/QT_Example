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

    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        qDebug("Errore socket Tcp");
    }

    out << "CIAO ZIO";

    while(1)
    {
        tcpSocket.write(block);
        tcpSocket.flush();
        //tcpSocket.waitForBytesWritten(3000);

        QThread::msleep(500);
    }

}
