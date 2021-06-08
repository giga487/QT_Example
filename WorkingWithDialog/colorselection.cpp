#include "colorselection.h"

ColorSelection::ColorSelection(QWidget* parent)
{
  m_cDialog = new QColorDialog(parent);
  m_cDialog->exec();
  m_appColor = new QColor();
  qDebug("SUKA costruttore");
  value = 0;
  QObject::connect(new QColorDialog(), &QColorDialog::colorSelected, this, &ColorSelection::HandleColorSelected);
  //connect(parent, SIGNAL(QColorDialog::colorSelected(m_appColor)), this, SLOT(ColorSelection::FunzioneDelCazzo()));
}

void ColorSelection::HandleColorSelected(QColor color)
{
    qDebug("SUKA");
    m_appColor = (QColor*)&color;

}
