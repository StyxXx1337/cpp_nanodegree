// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>


/* Instructions

    Create base class called Shape.
    Define pure virtual functions (= 0) for the base class.
    Write the derived classes.
        Inherit from class Shape.
        Override the pure virtual functions from the base class.
    Test in main()
*/



// TODO: Define pi
#define PI 3.141
// TODO: Define the abstract class Shape
class Shape{
  // TODO: Define public virtual functions Area() and Perimeter()
  // TODO: Append the declarations with = 0 to specify pure virtual functions
    virtual float Area() = 0;
    virtual float Perimeter() = 0;
};

// TODO: Define Rectangle to inherit publ:icly from Shape
class Rectangle: public Shape{
  public:
  // TODO: Declare public constructor
    Rectangle(float w, float h);
  // TODO: Override virtual base class functions Area() and Perimeter()
    float Area();
    float Perimeter();

  // TODO: Declare private attributes width and height
  private:
    float width_;
    float height_;
};

Rectangle::Rectangle(float w, float h): width_(w), height_(h){
    //Validate;
};

float Rectangle::Area(){
    return width_ * height_;
}

float Rectangle::Perimeter(){
    return (width_ + height_) * 2;
}


// TODO: Define Circle to inherit from Shape
class Circle: public Shape{
  public:
  // TODO: Declare public constructor
    Circle(float r): radius_(r){};
  // TODO: Override virtual base class functions Area() and Perimeter()
    float Area();
    float Perimeter();

  // TODO: Declare private member variable radius
  private:
    float radius_;
};

float Circle::Area(){
    return PI * radius_ * radius_;
}

float Circle::Perimeter(){
    return 2 * PI * radius_;
}

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}
