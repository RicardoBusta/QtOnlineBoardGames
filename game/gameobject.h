#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QPoint>
#include <QSize>
#include <QString>

enum OBJECT_TYPE{OBJECT_COMMON, OBJECT_DICE, OBJECT_DECK};

class GameObject
{
public:
  quint32 id;
  QPoint position;
  QSize size;
  QString imageURL;
  QString owner;
  bool movableByEveryone;
  bool visibleByEveryone;

  GameObject();
};

#endif // GAMEOBJECT_H
