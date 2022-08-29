#ifndef UNTITLED6__BALL_H_
#define UNTITLED6__BALL_H_



#include "lib_hyper_pong/items/abstractactiveitem.hpp"

class Ball : public AbstractActiveItem
{
 public:
  Ball();
  ~Ball();
  void reset(int newX, int newY, float initDX, float initDY) override;
  void update();
  void draw() override;
  void move() override;
  void applyDirection(float angle) override;
  void multiplySpeed(float koefficient) override;
  void applyVector(float newDX, float newDY) override;
  void applyPosition(float newX, float newY) override;
};



#endif //UNTITLED6__BALL_H_
