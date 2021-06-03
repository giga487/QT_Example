#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <encoderComm.h>


class ServerThread: public QThread
{
    Q_OBJECT
public:
    ServerThread(int socketDescriptor, QObject *parent = nullptr);
    void run() override;
private:
    qint16 m_intProva = 0;
    int socketDescriptor;
    MSG_KEEP_ALIVE *msg;

};


QDataStream &operator<<(QDataStream &stream,const MSG_KEEP_ALIVE *msg);

#endif // SERVERTHREAD_H
