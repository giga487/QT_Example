#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QDialog>
#include "DialogGeometry.h"
#include <QMessageBox>
#include <QtNetwork>
#include <serverthread.h>


class ServerEnc: QTcpServer
{
    Q_OBJECT
    public:
        ServerEnc(QObject *parent = nullptr);
        ~ServerEnc();

    private:
       QDialog *m_dialog = nullptr;
        QTcpServer *m_server = nullptr;
        ServerThread *m_serverThread = nullptr;

    protected:
        void incomingConnection(qintptr socketDescriptor) override;


};

#endif // SERVER_H
