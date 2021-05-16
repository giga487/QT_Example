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
    void HandleColorSelected(const QColor &color);

  private:
    QColorDialog *m_cDialog;
    QColor *m_appColor = new QColor();
    int value = 0;
};

#endif // COLORSELECTION_H
