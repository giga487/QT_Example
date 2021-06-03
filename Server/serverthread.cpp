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

    uint lengthMsg = sizeof(MSG_KEEP_ALIVE);
    uint lengthHeader = sizeof(MSG_HEADER);

    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        qDebug("Errore socket Tcp");
    }

    MSG_KEEP_ALIVE buffer;

    memset(&buffer, 0, 9);
    buffer.Header.Lunghezza = 1;
    buffer.Header.Sender = ID_ENCODER;
    buffer.Header.TipoMessaggio = ID_KEEP_ALIVE;
    buffer.Header.Contatore = 0;

    // |3 | 2 | 0 16 | 0000

    while(1)
    {

        tcpSocket.write((char*)&buffer.Header); //invio l'header
        tcpSocket.flush();
        //tcpSocket.waitForBytesWritten(3000);

        QThread::msleep(500);

        buffer.Header.Contatore++;
    }

}
