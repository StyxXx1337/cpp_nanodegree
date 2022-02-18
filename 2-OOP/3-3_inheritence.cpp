#include <iostream>
#include <string>
using std::string;

/**
 * Instructions

    Add a new member variable to class Vehicle.
    Output that new member in main().
    Derive a new class from Vehicle, alongside Car and Bicycle.
    Instantiate an object of that new class.
    Print the object.

 *
 */

class Vehicle {
 public:
  int wheels = 0;
  string color = "blue";
  int axles = 2;

  void Print() const {
    std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
  }
};

class Car : public Vehicle {
 public:
  bool sunroof = false;
};

class Bicycle : public Vehicle {
 public:
  bool kickstand = true;
};

class Truck : public Vehicle {

 public:
 Truck(){
     axles = 4;
     wheels = 8;
 }
  std::string body = "flatbed";

  void Print() const {
    std::cout << "This " << color << " truck has " << wheels << " wheels, on " << axles << " axels!\n";
  }
};

int main() {
  Car car;
  car.wheels = 4;
  car.sunroof = true;
  car.Print();
  if (car.sunroof)
    std::cout << "And a sunroof!\n";

  std::cout << "The car has " << car.axles << "axles.\n";
  Truck truck;
  truck.Print();
};