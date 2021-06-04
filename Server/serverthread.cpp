#include "serverthread.h"
#include <QtEndian>
#include <QBitArray>

ServerThread::ServerThread(int socketDescriptor, QObject *parent): QThread(parent), socketDescriptor(socketDescriptor)
{
    qDebug("Server thread init");
}


void ServerThread::run()
{
    QTcpSocket tcpSocket;

    QDataStream out;
    out.setDevice(&tcpSocket);
    out.setByteOrder(QDataStream::BigEndian);

    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        qDebug("Errore socket Tcp");
    }

    MSG_KEEP_ALIVE *buffer = new MSG_KEEP_ALIVE();

    memset(buffer, 0, sizeof(MSG_KEEP_ALIVE));
    buffer->Header.Lunghezza = 1;
    buffer->Header.Sender = ID_ENCODER;
    buffer->Header.TipoMessaggio = ID_KEEP_ALIVE;
    buffer->Header.Contatore = 0;

    memset((char*)&buffer->Body, 0, sizeof(MSG_KEEP_ALIVE_BODY));

    // |3 | 2 | 0 16 | 0000



    while(1)
    {
        out << buffer;
        tcpSocket.flush(); //https://stackoverflow.com/questions/42074728/writing-to-qtcpsocket-does-not-always-emit-readyread-signal-on-opposite-qtcpsock
        QThread::msleep(500);
        buffer->Header.Contatore++;
        buffer->Body.Disponibile8++;

    }

}


