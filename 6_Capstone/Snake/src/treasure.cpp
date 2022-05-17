#include "treasure.h"

constexpr int TIMER = 600;
constexpr int TOTAL_TIMER = 960;

Treasure::Treasure(int x, int y) {
  timing = TIMER;
  coordinate.x = x;
  coordinate.y = y;
}

Treasure::Treasure() {}

void Treasure::Update() {
  if (totalTime == 0) {
    totalTime = TOTAL_TIMER;
    timing = TIMER;
  } else {
    --timing;
    --totalTime;
  }
}

bool Treasure::isTreasure(int x, int y) {
  if (!alive) {
    return false;
  }

  if (coordinate.x == x && coordinate.y == y && (timing > 0)) {
    return true;
  }
  return false;
}

void Treasure::setAlive(bool b) { alive = b; }

bool Treasure::isAlive() const { return alive; }

void Treasure::resetTiming() { timing = TIMER; }

int Treasure::currentTime() const { return timing; }
