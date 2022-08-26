#ifndef UNTITLED6__GAME_H_
#define UNTITLED6__GAME_H_

#include <memory>
#include <vector>

#include "lib_hyper_pong/game/abstractgame.hpp"
#include "lib_hyper_pong/items/ball.hpp"
#include "lib_hyper_pong/items/verticalracket.hpp"
#include "lib_hyper_pong/items/score.hpp"
#include "lib_hyper_pong/items/horisontalwall.hpp"

#include "lib_hyper_pong/physengine/physengine.hpp"

class PongGame : public AbstractGame{

  std::vector<std::shared_ptr<AbstractActiveItem>> activeItems;
  std::vector<std::shared_ptr<AbstractPassiveItem>> passiveItems;

  PhysEngine engine;

  int ticks;
  Score score;
  void advanceCollisions();
  void advanceMovement();
  void advanceScoring();
 public:
  PongGame();
  ~PongGame();
  void update() override;
  void draw() override;
  bool isOver() override;

};

#endif //UNTITLED6__GAME_H_
