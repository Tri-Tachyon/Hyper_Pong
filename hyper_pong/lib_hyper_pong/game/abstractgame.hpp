#ifndef HYPER_PONG_HYPER_PONG_LIB_HYPER_PONG_GAME_ABSTRACTGAME_HPP_
#define HYPER_PONG_HYPER_PONG_LIB_HYPER_PONG_GAME_ABSTRACTGAME_HPP_

#include <memory>
#include <vector>


class AbstractGame {
 public:
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual bool isOver() = 0;

};

#endif //HYPER_PONG_HYPER_PONG_LIB_HYPER_PONG_GAME_ABSTRACTGAME_HPP_
