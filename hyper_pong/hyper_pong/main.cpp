#include <lib_hyper_pong/items/abstractitem.hpp>
#include "lib_hyper_pong/game/ponggame.hpp"


int main() {
  auto game = PongGame();
  while (!game.isOver()) {
    game.update();
    game.draw();
  }
  return 0;
}


void GameProcessInput() {}

void GameUpdate() {}
