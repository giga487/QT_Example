#include "threadnosimple.h"

ThreadNoSimple::ThreadNoSimple()
{
    setPriority(QThread::LowestPriority);   //QThread::IdlePriority to QThread::InheritPriority
}

void ThreadNoSimple::run()
{
    while(1)
    {
        qDebug() << "Thread["<< thread()->currentThreadId()<<","<<taskId<<"]: "<<n++<<" times";
        QThread::sleep(1);
    }

}

void ThreadNoSimple::passData(int n)
{
    taskId = n;
}
