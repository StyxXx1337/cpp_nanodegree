#ifndef OBJECTS_H_
#define OBJECTS_H_

#include "SDL.h"
#include <math.h>
#include <vector>

class Object {
public:
  Object(float x, float y) : x_(x), y_(y){};
  Object(float x, float y, float sx, float sy) : x_(x), y_(y), speed_x(sx), speed_y(sy){};
  Object(float x, float y, float sx, float sy, int h, int w)
      : x_(x), y_(y), speed_x(sx), speed_y(sy), grid_height(h), grid_width(w){};
  void GridSize(int h, int w);
  void Update();

  float x_;
  float y_;

private:
  float speed_x{0.0f};
  float speed_y{0.0f};
  int grid_width{0};
  int grid_height{0};
};

class Objects {
public:
  Objects(){};
  std::vector<Object> objects;
  bool isThereAnObject(int x, int y);
  void createWall(int x, int y);
};

#endif
