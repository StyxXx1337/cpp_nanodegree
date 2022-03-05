#include <iostream>
#include <string>

/* Instructions

Overloading can happen outside of an object-oriented context, too. In this exercise, you will practice overloading a normal function that is not a class member.

    Create a function hello() that outputs, "Hello, World!"
    Create a class Human.
    Overload hello() by creating a function hello(Human human). This function should output, "Hello, Human!"
    Create 2 more classes and use those classes to further overload the hello() function.
*/

// TODO: Write hello() function
void hello() {
  std::cout << "Hello world!" << std::endl;
}
// TODO: Overload hello() three times
class Human {};
void hello(Human h) { std::cout << "Hello Human!" << std::endl; }

class Dog {};
void hello(Dog d) { std::cout << "Hello Doggy! How cute are you?!?" << std::endl; }

class Cat {};
void hello(Cat c) { std::cout << "Hello kitty, kitty!" << std::endl; }

// TODO: Call hello() from main()
int main() {
  hello();
  hello(Human());
  hello(Dog());
  hello(Cat());
}