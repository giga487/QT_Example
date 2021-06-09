#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThreadPool>
#include <QMainWindow>
#include "qsimplethread.h"
#include "threadnosimple.h"

#define MAX_THREAD_COUNT 10

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void StartThreadPoolThread();
    void StartThread();

private:
    Ui::MainWindow *ui;
    QThreadPool* pool;
    QSimpleThread *simpleT;
    ThreadNoSimple *th;
    int nTask = 0;


};
#endif // MAINWINDOW_H
