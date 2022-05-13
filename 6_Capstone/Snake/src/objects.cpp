#include "objects.h"

bool Objects::isThereAnObject(int x, int y){
  for (auto const &obj : objects){
    if (obj.x_ == x && obj.y_ == y){
      return true;
    }
  }
  return false;
}
