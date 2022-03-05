#include <string>
#include <cstring>
#include <iostream>

/*
*    Create a class called Car.
*    Create 3 member variables: horsepower, weight and brand. The brand attribute must be a character array.
*    Create accessor and mutator functions for all member data.
*        The mutator function for brand must accept a C++ string as a parameter and
*        convert that string into a C-style string (a character array ending in null character) to set the value of brand.
*    The accessor function for the brand must return a string,
*        so in this function you first will need to convert brand to std::string, and then return it.
*/

class Car {
    // TODO: Declare private attributes
    private:
    int _horsepower {0};
    int _weight_kg {0};
    std::string _brand {"None"};

    // TODO: Declare getter and setter for brand
    public:
    void SetBrand(std::string brand);
    std::string GetBrand(void);

};

// Define setters
void Car::SetBrand(std::string brand){
  _brand = brand;
}

// Define getters
std::string Car::GetBrand(void){
  return _brand;
}


// Test in main()
int main()
{
    Car car;
    car.SetBrand("Peugeot");
    std::cout << car.GetBrand() << "\n";
}