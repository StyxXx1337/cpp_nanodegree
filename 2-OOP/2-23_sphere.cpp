#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
 public:
  Sphere(float radius);
  void Radius(float radius);

  // Accessors
  float Radius() const;
  float Volume() const;

 private:
  float _radius;
};

Sphere::Sphere(float radius) {
  Radius(radius);
}

void Sphere::Radius(float radius) {
  if (radius < 0) {
    throw std::invalid_argument("radius must be positive");
  } else {
    _radius = radius;
  }
}

float Sphere::Radius() const {
  return _radius;
}

float Sphere::Volume(void) const {
  return (4 * 3.14159265358979323846 * pow(_radius, 3)) / 3;
}

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  std::cout << sphere.Volume() << std::endl;
  assert(abs(sphere.Volume() - 523.6) < 1);
}