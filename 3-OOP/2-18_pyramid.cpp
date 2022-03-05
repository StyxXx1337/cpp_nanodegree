#include <cassert>
#include <stdexcept>

/******************************
Exercise: Pyramid Class
    Create a class: Pyramid.
    Create 3 attributes: length, width, and height.
    Create a constructor to initialize all the attributes.
    Create accessor and mutator functions for all attributes.
    Think about the appropriate invariants and enforce them by throwing exceptions.
    Create a member function to calculate the volume of the pyramid.
    Optional: create a member function to calculate the surface area of the pyramid.
**********************************/

// TODO: Define class Pyramid
class Pyramid{
// public class members
public:
// constructor
    Pyramid(int length, int width, int height){
      Width(width);
      Height(height);
      Length(length);
    };
// accessors
    int Length() const { return length_; }
    int Height() const { return height_; }
    int Width() const { return width_; }
// mutators
    void Length(int length);
    void Height(int height);
    void Width(int width);
// public Volume() function
    int Volume(void){
      return length_ * height_ * width_ / 3;
    }
    int Surface(void);

// private class members
  private:
    int height_;
    int width_;
    int length_;
};

void Pyramid::Length(int length){
  if (length > 0){
    length_ = length;
  }
  else{
    throw std::invalid_argument("Length must be a positive integer");
  }
}

void Pyramid::Width(int width){
  if (width > 0){
    width_ = width;
  }
  else{
    throw std::invalid_argument("Width must be a positive integer");
  }
}

void Pyramid::Height(int height){
  if (height > 0){
    height_ = height;
  }
  else{
    throw std::invalid_argument("Height must be a positive integer");
  }
}

int Pyramid::Surface(void){
  return 0;
}

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}