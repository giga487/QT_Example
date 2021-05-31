#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>

class ServerThread: public QThread
{
    Q_OBJECT
public:
    ServerThread(int socketDescriptor, QObject *parent = nullptr);
    void run() override;
private:
    qint16 m_intProva = 0;
    int socketDescriptor;
};

#endif // SERVERTHREAD_H
