#include "colorselection.h"

ColorSelection::ColorSelection(QWidget* parent)
{
  m_cDialog = new QColorDialog(parent);
  m_cDialog->exec();

  QObject::connect(m_cDialog, &QColorDialog::colorSelected, this, &ColorSelection::HandleColorSelected);

}

void ColorSelection::HandleColorSelected(const QColor &color)
{
  m_appColor = color;
}
