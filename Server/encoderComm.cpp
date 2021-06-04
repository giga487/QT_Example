
#include "encoderComm.h"

QDataStream &operator<<(QDataStream &stream,const MSG_KEEP_ALIVE *msg)
{
    stream << msg->Header.TipoMessaggio <<msg->Header.Sender << msg->Header.Lunghezza << msg->Header.Contatore;
    qDebug("TX: ID %d, S %d, L %d, Count %d",  msg->Header.TipoMessaggio,  msg->Header.Sender,  msg->Header.Lunghezza,  msg->Header.Contatore );
    return stream;
}
