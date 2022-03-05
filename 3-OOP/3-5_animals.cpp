#include <string>
#include <iostream>

/****
 *
 * Instructions

    Define a class Animal.
    Define 3 member variables: color, name, age.
    Define a derived class Snake that inherits from the base class Animal.
    Create a member variable length for the Snake class.
    Create a derived class Cat that inherits from the base class Animal.
    Create a member variable height for the Cat class.
    Create MakeSound() member functions for each of the derived classes.
    In the main() function instantiate Snake and Cat objects. Initialize both their unique and derived attributes. Program them to make a sound.
 *
 */

// Define base class Animal
class Animal{
  public:
    std::string name;
    std::string color;
    int age;
};

// Declare derived class Snake
class Snake : public Animal{
  public:
    float length;

    void MakeSound(){
        std::cout << "SsssSssssSsss~" << std::endl;
    }

};

// Declare derived class Cat
class Cat : public Animal{
  public:
    float height;

    void MakeSound(){
        std::cout << "MIau~ Miau~ Mauuu~!" << std::endl;
    }
};


// Test in main()
int main(){
    Snake snake;
    Cat cat;

    cat.name = "Azrael";
    cat.age = 12;
    cat.height = 47;

    snake.name = "Kaa";
    snake.age = 88;
    snake.length = 88.88;

    cat.MakeSound();
    snake.MakeSound();
}