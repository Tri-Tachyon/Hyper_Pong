#include <cmath>
#include <iostream>

#include "ball.hpp"


void Ball::reset(int newX, int newY, float initDX, float initDY) {
  x = newX;
  y = newY;
  dx = initDX;
  dy = initDY;
  skipNextMoveFrame = false;
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


void Ball::move() {
  if (skipNextMoveFrame) {
    skipNextMoveFrame = false;
    return;
  }
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
void Ball::applyPosition(float newX, float newY) {
  x = newX;
  y = newY;
}