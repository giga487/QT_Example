#include "signalbutton.h"


signalButton::signalButton(): signalButton(0)
{
}

signalButton::signalButton(const int &val)
{
  m_status = val;
}



void signalButton::setValue()
{
  m_status++;
  qDebug("Eccoci %d",m_status);
}



