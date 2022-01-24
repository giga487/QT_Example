#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class object : public QObject
{
    Q_OBJECT

    public:
        explicit object(QObject * parent = 0);

    signals:
        void transmit_to_gui(bool value);

    private slots:
        void receive_from_gui(bool value);

    private:
    bool state;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void transmit_to_object(bool value);

private slots:
    void receive_from_object(bool value);
    void on_checkBox_clicked();

private:
    Ui::MainWindow *ui;
    object m_object;
};







#endif // MAINWINDOW_H
