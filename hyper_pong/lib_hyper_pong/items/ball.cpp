#include <cmath>
#include <iostream>

#include "ball.hpp"


void Ball::reset(int newX, int newY, float initDX, float initDY) {
  x = newX;
  y = newY;
  dx = initDX;
  dy = initDY;
}

Ball::Ball() {
  type = BALL;
  size = BALL_SIZE;
  reset(WIN_WIDTH / 2, WIN_HEIGHT / 2, -1 * BALL_SPEED, 0);
}

Ball::~Ball() {

}

void Ball::update() {
  int newX = x+dx;
  int newY = y+dy;
  y = y + dy;
  x = x + dx;
}
void Ball::draw() {
  DrawCircle(x, y, size, Color(BALL_COLOR));

}

void Ball::interact(AbstractPassiveItem* item) {
  std::cout << "interacting with: " << typeid(item).name() << std::endl;
  if (item->getType() == ItemType::BALL) {
    //insert ball-to-ball collision
    return;
  }
  if (item->getType() == ItemType::VERTICAL_RACKET) {
    if (item->getX() - this->getSize() < this->getX() && this->getX() < item->getX() + this->getSize() ) {
      if (item->getY() - this->getSize() < this->getY() && this->getY() < item->getY() + item->getSize() + this->getSize()) {
        std::cout << "Collided!" << std::endl;
        dx = -dx;
      }
    }
    return;
  }

}

void Ball::move() {
  x += dx;
  y += dy;
}


void Ball::applyDirection(float angle) {
  float vel = sqrt(dy*dy + dx*dx);
  dy = sin(angle) * vel;
  dx = cos(angle) * vel;
}
void Ball::multiplySpeed(float koefficient) {
  dx *= koefficient;
  dy *= koefficient;
};
void Ball::applyVector(float newDX, float newDY){
 dx = newDX;
 dy = newDY;
}