#ifndef GAMEOBJECTGRAPHICITEM_H
#define GAMEOBJECTGRAPHICITEM_H

#include <QGraphicsItem>

#include "gameobject.h"

class GameObjectGraphicItem : public QGraphicsItem
{
public:
  explicit GameObjectGraphicItem();

protected:
  QRectF boundingRect() const;
  void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
  GameObject *gameObject;

  QImage img;
signals:

public slots:
};

#endif // GAMEOBJECTGRAPHICITEM_H
