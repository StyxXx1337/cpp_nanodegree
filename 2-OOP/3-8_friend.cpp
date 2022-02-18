// Example solution for Rectangle and Square friend classes
#include <assert.h>

/**
 * Instructions

    In this exercise you will experiment with friend classes.
    In the notebook below, implement the following steps:

    Declare a class Rectangle.
    Define a class Square.
    Add class Rectangle as a friend of the class Square.
    Add a private attribute side to class Square.
    Create a public constructor in class Square that initializes the side attribute.
    Add private members width and height to class Rectangle.
    Add a Rectangle() constructor that takes a Square as an argument.
    Add an Area() function to class Rectangle.
 *
 *
 */

// Declare class Rectangle
class Square;

class Rectangle{
  public:
    Rectangle(const Square& s);
    int Area(){ return width * height; };
  private:
    int width;
    int height;
};

// Define class Square as friend of Rectangle

class Square{
  public:
    Square(int s): side(s){};

  private:
    friend class Rectangle;
    int side;
};

Rectangle::Rectangle(const Square& s): width(s.side), height(s.side){};

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
}