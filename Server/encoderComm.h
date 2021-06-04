#ifndef ENCODERCOMM_H
#define ENCODERCOMM_H


#include <QThread>
#include <QTcpSocket>
#include <QByteArray>

typedef struct str_MsgKeepAliveBody
 {
    unsigned int Disponibile1;
    unsigned int  Disponibile2;
    unsigned int  Disponibile3;
    unsigned int  Disponibile4;
    unsigned int  Disponibile5;
    unsigned int  Disponibile6;
    unsigned int  Disponibile7;
    unsigned int  Disponibile8;
 } MSG_KEEP_ALIVE_BODY;

enum e_id_Prot_Encoder_RT_Tipo
{
    ID_MSG_RISPOSTA_OPERATIVO = 0x01,
    ID_MSG_PN = 0x02,
    ID_KEEP_ALIVE = 0x03,
    ID_MSG_RISPOSTA_AZZERAMENTO = 0x04,
    ID_MSG_DATI_INSTALLATIVI_SERVO = 0x05,
    ID_MSG_DATI_OPERATIVI = 0x06,
    ID_MSG_RISPOSTA_DATI_INSTALLATIVI_LIM_SERVO = 0x07,
    ID_MSG_RISPOSTA_OPERATIVO_LIM_SERVO = 0x08
};

enum e_id_Prot_Encoder_RT_Sender
{
    ID_RT = 0x01, ID_ENCODER = 0x02
};

typedef struct str_MsgHeader
{
    unsigned char TipoMessaggio;
    unsigned char Sender;
    unsigned short Lunghezza;
    unsigned int Contatore;
}MSG_HEADER;

typedef struct str_MsgKeepAlive
{
    MSG_HEADER Header;
    MSG_KEEP_ALIVE_BODY Body;
    //uint16_t CheckSum;
}MSG_KEEP_ALIVE;


typedef union msg_t
{
  char ch[9];
  MSG_KEEP_ALIVE msg_t;
}MSG_UNION;

QDataStream &operator>>(QDataStream &stream,const MSG_KEEP_ALIVE *msg);
QDataStream &operator<<(QDataStream &stream,const MSG_KEEP_ALIVE *msg);

#endif // ENCODERCOMM_H
