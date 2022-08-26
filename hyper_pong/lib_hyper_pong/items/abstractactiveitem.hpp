#ifndef UNTITLED6__ABSTRACTACTIVEITEM_H_
#define UNTITLED6__ABSTRACTACTIVEITEM_H_

#include <lib_hyper_pong/items/abstractpassiveitem.hpp>

class AbstractActiveItem : public AbstractPassiveItem
{
 protected:
  float dx;
  float dy;
 public:
  [[nodiscard]] float getDX() {return dx;};
  [[nodiscard]] float getDY() {return dy;};
  virtual void applyDirection(float angle) = 0;
  virtual void multiplySpeed(float koefficient) = 0;
  virtual void applyVector(float newX, float newY) = 0;
  virtual void interact(AbstractPassiveItem* item) = 0;
  virtual void reset(int newX, int newY, float initDX, float initDY) = 0;

  //undefined reference to `vtable for AbstractActiveItem' error means undefined virtual fumction
};

#endif //UNTITLED6__ABSTRACTACTIVEITEM_H_
