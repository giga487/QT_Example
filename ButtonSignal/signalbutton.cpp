#include "signalbutton.h"


signalButton::signalButton()
{
  m_status = 0;
}


void signalButton::setValue()
{
  m_status++;
  qDebug("Eccoci %d",m_status);
}



