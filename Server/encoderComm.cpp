
#include "encoderComm.h"

QDataStream &operator<<(QDataStream &stream,const MSG_KEEP_ALIVE *msg)
{
    stream << msg->Header.TipoMessaggio << msg->Header.Sender << msg->Header.Lunghezza << msg->Header.Contatore <<
              msg->Body.Disponibile1 << msg->Body.Disponibile2 << msg->Body.Disponibile3 << msg->Body.Disponibile4 <<
              msg->Body.Disponibile5 << msg->Body.Disponibile6 << msg->Body.Disponibile7 << msg->Body.Disponibile8;

    qDebug("TX: ID %d, S %d, L %d, Count %d",  msg->Header.TipoMessaggio,  msg->Header.Sender,  msg->Header.Lunghezza,  msg->Header.Contatore );
    return stream;
}
