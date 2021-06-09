#include "qsimplethread.h"
#include <QDebug>
#include <QString>

QSimpleThread::QSimpleThread()
{

}

void QSimpleThread::run()
{
    while(1)
    {
            qDebug() << "Runnable Thread["<<QThread::currentThreadId()<<"]: "<<n++<<" times";

            QThread::sleep(1);
    }

}
