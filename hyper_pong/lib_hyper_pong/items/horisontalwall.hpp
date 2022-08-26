#ifndef UNTITLED6__HORISONTALWALL_H_
#define UNTITLED6__HORISONTALWALL_H_

#include "lib_hyper_pong/items/abstractpassiveitem.hpp"

class HorisontalWall : public AbstractPassiveItem {

 public:
  HorisontalWall(int y);
  void move() override;
  void update() override;
  void draw() override;
};

#endif //UNTITLED6__HORISONTALWALL_H_
