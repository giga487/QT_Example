#include "customdialog.h"

CustomDialog::CustomDialog(QWidget *parent)
{
  custom = new QDialog(parent);
  QString labelBtnClose = "Chiudi il Gump";
  //buttonCustom = new QPushButton(labelBtnClose, custom);
  custom->show();
  //connect()
}


