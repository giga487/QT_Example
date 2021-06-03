#ifndef ENCODERCOMM_H
#define ENCODERCOMM_H


typedef struct str_MsgKeepAliveBody
 {
     unsigned Disponibile1 :8;
     unsigned Disponibile2 :8;
     unsigned Disponibile3 :8;
     unsigned Disponibile4 :8;
     unsigned Disponibile5 :8;
     unsigned Disponibile6 :8;
     unsigned Disponibile7 :8;
     unsigned Disponibile8 :8;
 }__attribute__((packed)) MSG_KEEP_ALIVE_BODY;

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
    unsigned char Lunghezza;
    unsigned char Contatore;
}MSG_HEADER;

typedef struct str_MsgKeepAlive
{
    MSG_HEADER Header;
    MSG_KEEP_ALIVE_BODY Body;
    //uint16_t CheckSum;
}__attribute__((packed))MSG_KEEP_ALIVE;


typedef union msg_t
{
  char ch[9];
  MSG_KEEP_ALIVE msg_t;
}MSG_UNION;


#endif // ENCODERCOMM_H
