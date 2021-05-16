#ifndef COLORSELECTION_H
#define COLORSELECTION_H

#include <QColorDialog>
#include <QObject>
#include <QDebug>

class ColorSelection: public QObject
{
  Q_OBJECT
  public:
    ColorSelection(QWidget* parent);
    QColor GetColor();
  public slots:
    void HandleColorSelected(QColor color);

  private:
    QColorDialog *m_cDialog;
    QColor *m_appColor;
    int value;
};

#endif // COLORSELECTION_H
