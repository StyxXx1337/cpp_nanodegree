#include <iostream>
#include <string>
#include <assert.h>

/*
Instructions

    Review class Dog, which inherits from both Animal and Pet.
    Declare a class Cat, with a member attribute color, that also inherits from both Animal and Pet.
    Instantiate an object of class Cat.
    Configure that object to pass the tests in main().
*/

class Animal {
public:
    double age;
};

class Pet {
public:
    std::string name;
};

// Dog derives from *both* Animal and Pet
class Dog : public Animal, public Pet {
public:
    std::string breed;
};

class Cat: public Animal, public Pet {
public:
    std::string color;
};

int main()
{
    Cat cat;
    cat.age = 10.;
    cat.color = "black";
    cat.name = "Max";
    assert(cat.color == "black");
    assert(cat.age == 10);
    assert(cat.name == "Max");
}