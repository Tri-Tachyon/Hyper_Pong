#ifndef UNTITLED6__PHYSENGINE_H_
#define UNTITLED6__PHYSENGINE_H_

#include "lib_hyper_pong/items/ball.hpp"
#include "lib_hyper_pong/items/verticalracket.hpp"

#include <lib_hyper_pong/config.hpp>



class PhysEngine {
  float maxReflectionAngle = MAX_REFL_ANGLE;
  float speedIncrement = SPEED_INCREMENT;
  //Avoidin casts at all cost:
  void interactBall_VerticalRacket(AbstractActiveItem* ball, AbstractPassiveItem* racket);
  void interactBall_HorisontalWall(AbstractActiveItem* ball, AbstractPassiveItem* wall);
 public:
  void interact(AbstractActiveItem* aItem, AbstractPassiveItem* pItem); //running into Wadler's Expression Problem
  void interact(AbstractActiveItem* item1, AbstractActiveItem* item2);
  //passive items cannot interact with each other
};

#endif //UNTITLED6__PHYSENGINE_H_
