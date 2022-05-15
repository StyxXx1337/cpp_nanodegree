#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <vector>
class Object {
public:
  Object(int x, int y): x_(x), y_(y){};
  int x_;
  int y_;
};

class Objects {
public:
  Objects(){};
  std::vector<Object> objects;
  bool isThereAnObject(int x, int y);
  void createWall(int x, int y);

};


#endif
