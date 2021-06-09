#ifndef QSIMPLETHREAD_H
#define QSIMPLETHREAD_H

#include <QObject>
#include <QThread>
#include <QThreadPool>

class QSimpleThread: public QRunnable
{
public:
    QSimpleThread();
    void run() override;
private:
    int n = 0;
};

#endif // QSIMPLETHREAD_H
