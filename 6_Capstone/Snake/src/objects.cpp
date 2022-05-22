#include "objects.h"
#include <iostream>


void Object::Update(){
  SDL_Point prev_cell{
      static_cast<int>(x_),
      static_cast<int>(y_)};
  x_ += speed_x;
  y_ += speed_y;
  
  SDL_Point current_cell{
      static_cast<int>(x_),
      static_cast<int>(y_)};

  x_ = fmod(x_ + grid_width, grid_width);
  y_ = fmod(y_ + grid_height, grid_height);
}

void Object::GridSize(int h, int w){
  grid_height = h;
  grid_width = w;
}

bool Objects::isThereAnObject(int x, int y) {
  for (auto const &obj : objects) {
    if ((abs(obj.x_ - x) < 1) && (abs(obj.y_ - y) < 1)) {
      return true;
    }
  }
  return false;
}

void Objects::createWall(int x_max, int y_max) {
  int x{0};
  int y{0};

  while (x <= x_max) {
    objects.push_back(Object(x, 0));
    objects.push_back(Object(x, y_max - 1));
    ++x;
  }
  while (y <= y_max) {
    objects.push_back(Object(0, y));
    objects.push_back(Object(x_max - 1, y));
    ++y;
  }
}
