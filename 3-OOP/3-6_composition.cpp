#include <iostream>
#include <cmath>
#include <assert.h>

/* Instructions

In this exercise, you will start with a LineSegment class and create a Circle class.

Note that you will compose Circle from LineSegment, instead of inheriting Circle from LineSegment.
Specifically, the length attribute from LineSegment will become the circle's radius.

    Create a class LineSegment.
    Declare an attribute length in class LineSegment.
    Define pi (3.14159) with a macro.
    Create a class Circle, composed of a LineSegment that represent's the circle's radius.
    Use this radius to calculate the area of the circle (area of a circle = πr2\pi r^2πr2).
    Verify the behavior of Circle in main().
*/

// Define pi
#define PI 3.141592653589793

// Define Line Class
class LineSegment {
  // Define protected attribute length
  public:
    LineSegment(float len): length(len) {};
    void setLength(float len){ length = len; };
    float getLength() const { return length; };
  protected:
    float length;
};


// Define Circle subclass
class Circle {
  public:
    Circle(float r): radius(r){};
    Circle(LineSegment l): radius(l){};
    void setRadius(float r){ radius.setLength(r); };
    float getArea(){ return (radius.getLength() * radius.getLength() * PI); }
  private:
    LineSegment radius;
};
// Define public setRadius() and getArea()

// Test in main()
int main()
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.getArea()) == 28);
    // radius.length = 100;
    // assert(radius.length == 100);
}