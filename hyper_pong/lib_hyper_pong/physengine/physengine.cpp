#include "physengine.hpp"

#include <iostream>
#include <cmath>

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

float inline getDistance(float x1, float y1, float x2, float y2) {
  return std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
}
bool inline isPointInBetween(float x, float x1, float x2) {
  return ((x - x1) * (x - x2)) <= 0;
}

float inline getCollisionCoef(float collX, float x1, float x2) {
  return (collX - x1) * 2 / (x2 - x1) - 1;
}

// todo: revise formula
float inline getReflectedPosition(float ballX, float ballDX, float wallX) {
  return wallX - (std::abs(ballDX) / ballDX) * std::abs(ballDX - std::abs(wallX - ballX));
}

float inline getYOfIntersection(float vLineX, float lineX, float lineY, float vecX, float vecY) {
  return lineY + ((vecY / vecX) * (vLineX - lineX));
} //calcylates y of point of intersection of line and vertical line. line is defined by any point and a guiding vec

void PhysEngine::interactBall_VerticalRacket(AbstractActiveItem* ball, AbstractPassiveItem* racket){

  const float racketX = racket->getX();
  const float ballX = ball->getX();

  if (racketX == ballX) return;

  const float ballDX = ball->getDX();
  const int ballRadius = ball->getSize();

  if (!isPointInBetween(racketX , ballX, ballX + ballDX)) return; // is ball close enough to interact

  const float ballY = ball->getY();
  const float ballDY = ball->getDY();
  const float intersectionY = getYOfIntersection(racketX, ballX, ballY, ballDX, ballDY);

  const float racketY1 = racket->getY();
  const float racketY2 = racket->getY() + racket->getSize();

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

  //moving the ball in a broken line:

  ball->applyPosition(getReflectedPosition(ballX, ballDX, racketX), ballY + ballDY);
  ball->skipNextMove();

  std::cout << "intersected!" << std::endl;
  const float collisionCoef = getCollisionCoef(ballY, racketY1, racketY2);

  float newAngle = maxReflectionAngle * collisionCoef;

  if (ballDX > 0) newAngle = newAngle + 2 * (M_PI_2 - newAngle);

  std::cout << "xdist:"<< racket->getX() - ball->getX() << std::endl;
  std::cout << "Collided: ------------------------------------------------------------" << collisionCoef << std::endl;
  ball->applyDirection(newAngle);
  ball->multiplySpeed(speedIncrement);
}

void PhysEngine::interactBall_HorisontalWall(AbstractActiveItem* ball, AbstractPassiveItem* wall) {
  const float wallY= wall->getY();
  const float ballY = ball->getY();
  const float ballDY = ball->getDY();
  const int ballRadius = ball->getSize();

  if (!isPointInBetween(wallY , ballY, ballY + ballDY)) return; // is ball close enough to interact

  const float ballDX = ball->getDX();


  //moving the ball in a broken line:
  const float ballX = ball->getX();
  ball->applyPosition(ballX + ballDX, getReflectedPosition(ballY, ballDY, wallY));
  ball->skipNextMove();

  ball->applyVector(ballDX, -1 * ballDY);

  std::cout << "Collides!_____________________________________________________________________"<< std::endl;
}