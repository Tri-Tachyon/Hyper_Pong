#ifndef UNTITLED6__VERTICALRACKET_H_
#define UNTITLED6__VERTICALRACKET_H_

#include "lib_hyper_pong/items/abstractpassiveitem.hpp"

class VerticalRacket : public AbstractPassiveItem
{
  int owner;
  void moveUp();
  void moveDown();
 public:
  VerticalRacket(int owner);
  void update();
  void move() override;
  void draw() override;
};




#endif //UNTITLED6__VERTICALRACKET_H_
