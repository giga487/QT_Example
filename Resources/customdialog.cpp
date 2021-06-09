#include "customdialog.h"

#define WIDTH 400
#define HEIGHT 400

CustomDialog::CustomDialog(QWidget *parent, bool _modalStyle, QString label): QDialog(parent)
{
  this->setModal(_modalStyle);

  /* definzione grafica del custom dialog */
  int posX = parent->geometry().x();
  int posY = parent->geometry().y();

  this->setGeometry(posX, posY, 400, 400);

  QLabel *testo = new QLabel(this);

  testo->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
  testo->setText(label);

  this->show();
}


