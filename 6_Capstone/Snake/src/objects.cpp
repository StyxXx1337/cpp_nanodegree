#include "objects.h"

bool Objects::isThereAnObject(int x, int y){
  for (auto const &obj : objects){
    if (obj.x_ == x && obj.y_ == y){
      return true;
    }
  }
  return false;
}

void Objects::createWall(int x_max, int y_max){
  int x {0};
  int y {0};

  while (x <= x_max){
    objects.push_back(Object(x, 0));
    objects.push_back(Object(x, y_max-1));
    ++x;
  }
  while (y <= y_max){
    objects.push_back(Object(0, y));
    objects.push_back(Object(x_max-1, y));
    ++y;
  }
  
}
