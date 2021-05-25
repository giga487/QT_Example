#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QLineEdit>
#include <QDialog>

class CustomDialog
{
  Q_OBJECT

  public:
   CustomDialog(QWidget *parent = nullptr);

  private:
    QDialog *custom;
    QPushButton *buttonCustom;
};

#endif // CUSTOMDIALOG_H
