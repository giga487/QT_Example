#ifndef AMATOTHREAD_H
#define AMATOTHREAD_H

#include <QObject>
#include <QThread>

class AmatoThread: public QThread
{
    Q_OBJECT
public:
    AmatoThread();
};

#endif // AMATOTHREAD_H
