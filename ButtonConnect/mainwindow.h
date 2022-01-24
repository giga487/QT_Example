#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class IntClass: public QObject
{
    Q_OBJECT
public:
    IntClass();
    IntClass(const int &);
    ~IntClass();
    void Increment();
    void Decrement();


    IntClass& operator=(const IntClass &);
    //bool operator==(const IntClass&) const;
    IntClass* operator+(const IntClass &) const;
    int GetValue() const;

public slots:
    void SetValue(const int&);

protected:
    int m_value;

};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CopyObj();
    void SumCopy();

private:
    Ui::MainWindow *ui;

protected:
    QPushButton *m_buttonIncrement = nullptr;
    QPushButton *m_buttonDecrement = nullptr;
    QPushButton *m_buttonReset = nullptr;
    QPushButton *m_buttonCopy = nullptr;
    QPushButton *m_buttonAddCopy = nullptr;
    IntClass *obj = nullptr;
    IntClass *anotherObj = nullptr;
    IntClass assignementCopy;
    IntClass sumCopy;

signals:
    void SentTo(const int&);

public slots:
    void on_dial_valueChanged(int value);
    void ReceiveFrom(const int&);
};




#endif // MAINWINDOW_H

