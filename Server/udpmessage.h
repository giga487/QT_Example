#ifndef UDPMESSAGE_H
#define UDPMESSAGE_H

#include <QObject>
#include <QUdpSocket>

class UdpMessage: public QObject
{
    Q_OBJECT
  public:
    UdpMessage(QObject *parent = nullptr);
    void Received();
    void MsgUdp();
  private:
    QUdpSocket *socket;
};

#endif // UDPMESSAGE_H
