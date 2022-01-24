#ifndef SIGNALBUTTON_H
#define SIGNALBUTTON_H


#include<QDebug>

class signalButton
{
  public:
    signalButton();
    signalButton(const int&);
    void setValue();

  private:
    int m_status;
};

#endif // SIGNALBUTTON_H
