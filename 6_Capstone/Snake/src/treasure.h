#ifndef TREASURE_H_
#define TREASURE_H_

#include "SDL.h"

class Treasure {
public:
  Treasure();
  Treasure(int x, int y);
  void Update(void);
  bool isTreasure(int x, int y);
  void setAlive(bool b);
  bool isAlive() const;
  void resetTiming();
  int currentTime() const;
  SDL_Point coordinate;

  int timing;
  int totalTime;

private:
  bool alive{false};
};

#endif
