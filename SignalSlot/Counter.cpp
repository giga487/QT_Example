#include "counter.h"

Counter::Counter()
{
  m_value = 0;
}


void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value); //EMIT, gestisce l'interrupt. fa partire il connect
    }
}

int Counter::getValue()
{
  return m_value;
}
