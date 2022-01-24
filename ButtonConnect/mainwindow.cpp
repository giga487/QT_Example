#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    obj = new IntClass();
    anotherObj = new IntClass();

    m_buttonIncrement = new QPushButton(this);
    m_buttonIncrement->setObjectName(QString::fromUtf8("Increment"));
    m_buttonIncrement->setGeometry(0,0,100,50);
    m_buttonIncrement->setText("Increment");

    m_buttonDecrement = new QPushButton(this);
    m_buttonDecrement->setObjectName(QString::fromUtf8("Decrement"));
    m_buttonDecrement->setGeometry(105,0,100,50);
    m_buttonDecrement->setText("Decrement");

    m_buttonReset = new QPushButton(this);
    m_buttonReset->setObjectName(QString::fromUtf8("Reset"));
    m_buttonReset->setGeometry(210,0,100,50);
    m_buttonReset->setText("Reset");

    m_buttonCopy = new QPushButton(this);
    m_buttonCopy->setObjectName(QString::fromUtf8("Reset"));
    m_buttonCopy->setGeometry(315,0,100,50);
    m_buttonCopy->setText("Copy");

    m_buttonAddCopy = new QPushButton(this);
    m_buttonAddCopy->setObjectName(QString::fromUtf8("Reset"));
    m_buttonAddCopy->setGeometry(0,105,100,50);
    m_buttonAddCopy->setText("Copy");

    QObject::connect(m_buttonIncrement, &QPushButton::clicked, obj, &IntClass::Increment);

    QObject::connect(m_buttonDecrement, &QPushButton::clicked, obj, &IntClass::Decrement);
    QObject::connect(m_buttonCopy, &QPushButton::clicked, this, &MainWindow::CopyObj);
    QObject::connect(m_buttonAddCopy, &QPushButton::clicked, this, &MainWindow::SumCopy);
    bool success = QObject::connect(this, SIGNAL(SentTo(const int&)), obj, SLOT(SetValue(const int&)));
    Q_ASSERT(success);
}

void MainWindow::SumCopy()
{
    IntClass *newObj = *obj + assignementCopy;

    emit newObj->GetValue();
    sumCopy = *newObj;
    delete newObj;
}

void MainWindow::CopyObj()
{
    assignementCopy = *obj;
    emit assignementCopy.GetValue();
}

MainWindow::~MainWindow()
{
    delete ui;
}

IntClass::IntClass(): IntClass(0)
{
}

IntClass::IntClass(const int &val)
{
    m_value = val;
}

IntClass::~IntClass()
{
}

void IntClass::SetValue(const int &value)
{
    m_value = value;
}

int IntClass::GetValue() const
{
    qDebug()<< m_value;
    return m_value;
}

void IntClass::Increment()
{
    m_value++;
}

void IntClass::Decrement()
{
    m_value--;
}

IntClass& IntClass::operator=(const IntClass &toAssign)
{
    if(this == &toAssign)
        return *this;

    m_value = toAssign.m_value;

    qDebug() << "Assignement operator used "<< m_value;
    return *this;
}

IntClass* IntClass::operator+(const IntClass &check) const
{
    int tempValue = m_value + check.GetValue();
    IntClass *temp = new IntClass(tempValue);

    return temp;
}


void MainWindow::on_dial_valueChanged(int value)
{
    emit SentTo(value);
}

void MainWindow::ReceiveFrom(const int& value)
{
    qDebug()<< "Received "<< value;
}
