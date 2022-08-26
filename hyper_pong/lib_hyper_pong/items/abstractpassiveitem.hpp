#ifndef UNTITLED6__ABSTRACTPASSIVEITEM_H_
#define UNTITLED6__ABSTRACTPASSIVEITEM_H_

#include <lib_hyper_pong/items/abstractitem.hpp>

enum ItemType { //Is it a bad design? Should be better then RTTI
  NO_TYPE,
  BALL,
  VERTICAL_RACKET,
  HORIZONTAL_WALL
};

class AbstractPassiveItem : public AbstractItem // Should probably create abstract factory?
{
 protected:
  ItemType type = NO_TYPE;
  float x = 0;
  float y = 0;
  int size = 0;
 public:


  [[nodiscard]] ItemType getType() const { return type; }
  [[nodiscard]] float getX() const {return x;}
  [[nodiscard]] float getY() const {return y;}
  [[nodiscard]] int getSize() const {return size;}

  virtual void move() = 0;
};

#endif //UNTITLED6__ABSTRACTPASSIVEITEM_H_
