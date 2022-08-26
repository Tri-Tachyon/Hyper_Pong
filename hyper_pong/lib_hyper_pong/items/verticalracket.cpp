#include "verticalracket.hpp"

VerticalRacket::VerticalRacket(int owner) : owner(owner) {
  size = RACKET_HEIGHT;
  type = VERTICAL_RACKET;
  y = GetScreenHeight() / 2 - size / 2;
  if (owner == 0) {
    x = RACKET_DEPTH;
    return;
  }
  x = GetScreenWidth() - RACKET_DEPTH;
}

void VerticalRacket::moveUp() {
  if (y < 0) return;
  y = y - RACKET_SPEED;
}

void VerticalRacket::moveDown() {
  if (y + size > GetScreenHeight()) return;
  y = y + RACKET_SPEED;
}

void VerticalRacket::update() {
  if (owner == 0) {
    if (IsKeyDown(LEFT_UP_KEY)) {
      moveUp();
      return;
    }
    if (IsKeyDown(LEFT_DOWN_KEY)) {
      moveDown();
      return;
    }
    return;
  }

  if (IsKeyDown(RIGHT_UP_KEY)) {
    moveUp();
    return;
  }
  if (IsKeyDown(RIGHT_DOWN_KEY)) {
    moveDown();
    return;
  }
}


void VerticalRacket::draw() {
  if (owner == 0) {
    DrawRectangle(x, y, -1 * RACKET_WIDTH, size, RACKET_COLOR);
  }
  DrawRectangle(x, y, RACKET_WIDTH, size, RACKET_COLOR);
}

void VerticalRacket::move() {
  if (owner == 0) {
    if (IsKeyDown(LEFT_UP_KEY)) {
      moveUp();
      return;
    }
    if (IsKeyDown(LEFT_DOWN_KEY)) {
      moveDown();
      return;
    }
    return;
  }

  if (IsKeyDown(RIGHT_UP_KEY)) {
    moveUp();
    return;
  }
  if (IsKeyDown(RIGHT_DOWN_KEY)) {
    moveDown();
    return;
  }
}