#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QLineEdit>
#include <QDialog>
#include <QLabel>

class CustomDialog: public QDialog
{
  Q_OBJECT

  public:
   CustomDialog(QWidget *parent = nullptr, bool _modalStyle = false, QString _label = "Dialog");

  private:
    QDialog *custom;
    QPushButton *buttonCustom;
};

#endif // CUSTOMDIALOG_H
