#include "colorselection.h"

ColorSelection::ColorSelection(QWidget* parent)
{
  m_cDialog = new QColorDialog(parent);
  m_cDialog->exec();
  m_appColor = new QColor();
 value = 0;
  QObject::connect(m_cDialog, &QColorDialog::colorSelected, this, &ColorSelection::HandleColorSelected);

}

void ColorSelection::HandleColorSelected(QColor color)
{
    qDebug("SUKA");
  m_appColor = (QColor*)&color;

}
