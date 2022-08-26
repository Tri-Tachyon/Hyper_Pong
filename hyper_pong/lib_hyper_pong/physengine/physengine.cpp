#include "physengine.hpp"

#include <iostream>
#include <math.h>

void PhysEngine::interact(AbstractActiveItem* item1, AbstractActiveItem* item2) {

}

void PhysEngine::interact(AbstractActiveItem* aItem, AbstractPassiveItem* pItem) {
  if (aItem->getType() == ItemType::BALL){
    if (pItem->getType() == ItemType::VERTICAL_RACKET) {
      interactBall_VerticalRacket(aItem, pItem);
      return;
    }
    if (pItem->getType() == ItemType::HORIZONTAL_WALL) {
      interactBall_HorisontalWall(aItem, pItem);
      return;
    }
  }
}

bool inline isPointInBetween(float x, float x1, float x2) {
  return ((x - x1) * (x - x2)) <= 0;
}

float inline getCollisionCoef(float collX, float x1, float x2) {
  return (collX - x1) * 2 / (x2 - x1) - 1;
}

float inline getYOfIntersection(float vLineX, float lineX, float lineY, float vecX, float vecY) {
  return lineY + ((vecY / vecX) * (vLineX - lineX));
} //calcylates y of point of intersection of line and vertical line. line is defined by any point and a guiding vec

void PhysEngine::interactBall_VerticalRacket(AbstractActiveItem* ball, AbstractPassiveItem* racket){
  std::cout << "interacting with: Racket: " << racket->getX() << std::endl;

  float racketX = racket->getX();
  float ballX = ball->getX();
  float ballDX = ball->getDX();
  int ballRadius = ball->getSize();

  if (!isPointInBetween(racketX , ballX, ballX + ballDX)) return; // is ball close enough to interact

  float ballY = ball->getY();
  float ballDY = ball->getDY();
  float intersectionY = getYOfIntersection(racketX, ballX, ballY, ballDX, ballDY);

  float racketY1 = racket->getY();
  float racketY2 = racket->getY() + racket->getSize();

  std::cout << "close enough!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
  std::cout << "ballX: " << ballX << std::endl;
  std::cout << "ballY: " << ballY << std::endl;
  std::cout << "ballDX: " << ballDX << std::endl;
  std::cout << "ballDY: " << ballDY << std::endl;
  std::cout << "intY: " << intersectionY << std::endl;
  std::cout << "racketX: " << racketX << std::endl;
  std::cout << "racketY1: " << racketY1 << std::endl;
  std::cout << "racketY2: " << racketY2 << std::endl;

  if (!isPointInBetween(intersectionY, racketY1, racketY2)) return;
  std::cout << "intersected!" << std::endl;
  float collisionCoef = getCollisionCoef(ballY, racketY1, racketY2);

  float newAngle = maxReflectionAngle * collisionCoef;

  if (ballDX > 0) newAngle = newAngle + 2 * (M_PI_2 - newAngle);

  std::cout << "xdist:"<< racket->getX() - ball->getX() << std::endl;
  std::cout << "Collided: ------------------------------------------------------------" << collisionCoef << std::endl;
  ball->applyDirection(newAngle);
  ball->multiplySpeed(speedIncrement);

}

void PhysEngine::interactBall_HorisontalWall(AbstractActiveItem* ball, AbstractPassiveItem* wall) {
  std::cout << "interacting with: Wall: " << wall->getY() << std::endl;
  float wallY= wall->getY();
  float ballY = ball->getY();
  float ballDY = ball->getDY();
  int ballRadius = ball->getSize();

  if (!isPointInBetween(wallY , ballY, ballY + ballDY)) return; // is ball close enough to interact

  float ballDX = ball->getDX();
  ball->applyVector(ballDX, -1 * ballDY);
  ball->move();

  std::cout << "Collides!_____________________________________________________________________"<< std::endl;
}