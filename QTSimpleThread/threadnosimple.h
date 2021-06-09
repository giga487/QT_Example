#ifndef THREADNOSIMPLE_H
#define THREADNOSIMPLE_H

#include <QObject>
#include <QThread>
#include <QDebug>

class ThreadNoSimple: public QThread
{
public:
    ThreadNoSimple();
    void run();
    void passData(int n);
private:
    int n = 0;
    int taskId = 0;
};

#endif // THREADNOSIMPLE_H
