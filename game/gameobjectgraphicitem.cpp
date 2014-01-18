#include "gameobjectgraphicitem.h"

#include <QPainter>
#include <QWidget>

GameObjectGraphicItem::GameObjectGraphicItem(GameObject *gameObject):
  gameObject(gameObject)
{
  //objectData = new GameObject();
  //gameObject->position = QPointF(0,0).toPoint();

  img = QImage(gameObject->imageURL);
  gameObject->size = img.size();

  setFlag(ItemIsMovable);
  setFlag(ItemSendsGeometryChanges);
  //setCacheMode(DeviceCoordinateCache);
  //setZValue(-1);
}

QRectF GameObjectGraphicItem::boundingRect() const
{
  if(gameObject != NULL){
    QRectF rect(gameObject->position,gameObject->size);
    return rect;
  }else{
    return QRectF(0,0,0,0);
  }
}

void GameObjectGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  if(gameObject != NULL){
    QRectF rect(gameObject->position,gameObject->size);
    //painter->drawRect(rect);
    painter->drawImage(rect,img);
  }
}
