#ifndef UNTITLED6__SCORE_H_
#define UNTITLED6__SCORE_H_

#include "lib_hyper_pong/items/abstractitem.hpp"

class Score : AbstractItem {
 public:
  void scoreLeft();
  void scoreRight();
  void update() override;
  void draw() override;
};

#endif //UNTITLED6__SCORE_H_
