#include "boardcanvaswidget.h"

QImage board("://images/board.png");
QImage black("://images/black.png");
QImage white("://images/white.png");

BoardCanvasWidget::BoardCanvasWidget(QWidget *parent) :
  QGraphicsView(parent)
{
}
