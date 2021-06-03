#include "serverthread.h"
#include <QtEndian>


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

    MSG_KEEP_ALIVE *buffer = new MSG_KEEP_ALIVE();

    memset(buffer, 0, 5);
    buffer->Header.Lunghezza = 1;
    buffer->Header.Sender = ID_ENCODER;
    buffer->Header.TipoMessaggio = ID_KEEP_ALIVE;
    buffer->Header.Contatore = 0;

    MSG_UNION un;

    un.msg_t = *buffer;

    // |3 | 2 | 0 16 | 0000


    while(1)
    {

        tcpSocket.write(un.ch); //invio l'header
        tcpSocket.flush();
        //tcpSocket.waitForBytesWritten(3000);

        QThread::msleep(500);
        un.msg_t.Header.Contatore++;

    }

}

