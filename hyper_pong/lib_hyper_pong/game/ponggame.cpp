#include <iostream>

#include"ponggame.hpp"

PongGame::PongGame() : ticks(0) {

  SetTargetFPS(TARGET_FPS);
  InitWindow(WIN_WIDTH, WIN_HEIGHT,
             "Pong by vvokhom");

  passiveItems.reserve(4);
  activeItems.push_back(std::make_shared<Ball>());
  passiveItems.push_back(std::make_shared<VerticalRacket>(0));
  passiveItems.push_back(std::make_shared<VerticalRacket>(1));
  passiveItems.push_back(std::make_shared<HorisontalWall>(0));
  passiveItems.push_back(std::make_shared<HorisontalWall>(WIN_HEIGHT));
}

void PongGame::advanceCollisions() {

  for (auto active = activeItems.begin(); active != activeItems.end(); ++active){
    for (auto passive = passiveItems.begin(); passive != passiveItems.end(); ++passive){
      engine.interact(active->get(), passive->get());
    }
  }

  for (auto first = activeItems.begin(); first != activeItems.end(); ++first){
    for (auto second = first + 1; second != activeItems.end(); ++second){
      engine.interact(first->get(), second->get());
    }
  }
}

void PongGame::advanceMovement() {
  for (auto& item : activeItems) {
    item->move();
  }
  for (auto& item : passiveItems) {
    item->move();
  }
}

void PongGame::advanceScoring() {
  for (auto& item : activeItems) {
    if (item->getType() != BALL) return;
    if (item->getX() < 0) {
      score.scoreRight();
      item->reset(WIN_WIDTH / 2, WIN_HEIGHT / 2, -1 * BALL_SPEED, 0);
      return;
    }
    if (item->getX() > WIN_WIDTH) {
      score.scoreLeft();
      item->reset(WIN_WIDTH / 2, WIN_HEIGHT / 2,BALL_SPEED, 0);
      return;
    }
    if(item->getY() < 0 || item->getY() > WIN_HEIGHT)  {
      item->reset(WIN_WIDTH / 2, WIN_HEIGHT / 2, -1 * BALL_SPEED, 0);
      return;
    }
  }
}


void PongGame::update() {

  score.update();
  ticks++;
  std::cout<<ticks<<std::endl;
  advanceCollisions();
  advanceMovement();
  advanceScoring();
}

void PongGame::draw() {
  BeginDrawing();
  ClearBackground(BACKGROUND_COLOR);

  for (auto& item : activeItems) {
    item->draw();
  }
  for (auto& item : passiveItems) {
    item->draw();
  }

  score.draw();
  EndDrawing();
}

bool PongGame::isOver() {
  return WindowShouldClose();
}

PongGame::~PongGame() {
}
