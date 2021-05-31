#include "server.h"

/* questa classe istanzia il server tcp/udp e attende la comunicazione */
ServerEnc::ServerEnc(QObject *parent): QTcpServer(parent)
{
    qDebug("Init server");

    if (!listen(QHostAddress::LocalHost, 60000))
    {
        qDebug("Error on start socket");
        return;
    }

    qDebug("Server is listening at port %d", serverPort());
}

ServerEnc::~ServerEnc()
{

}

void ServerEnc::incomingConnection(qintptr socketDescriptor)
{
    qDebug("Connection found");

    m_serverThread = new ServerThread(socketDescriptor, this);
    ServerThread *serverIncomingConn = new ServerThread(socketDescriptor, this);
    connect(serverIncomingConn, &ServerThread::finished, serverIncomingConn, &ServerThread::deleteLater);
    serverIncomingConn->start();
}
