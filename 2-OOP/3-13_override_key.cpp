#include <assert.h>
#include <cmath>

// Instructions

//     Define class ParticleModel, including its state and Move() function.
//     Extend class BicycleModel from class ParticleModel.
//     Override the Move() function within class BicycleModel.
//     Specify BicycleModel::Move() as override.
//     Pass the tests in main() by verifying that the two Move() functions override each other in different scenarios.


// TODO: Define PI
#define PI 3.141
// TODO: Declare abstract class VehicleModel
class VehicleModel{
  // TODO: Declare virtual function Move()
    virtual void Move(double v, double phi) = 0;
};

// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : public VehicleModel{
public:
  // TODO: Override the Move() function
  void Move(double v, double phi) override;
  // TODO: Define x, y, and theta
  double x {.0};
  double y {.0};
  double theta {.0};
};

void ParticleModel::Move(double v, double phi){
  theta += phi;
  x = v * cos(theta);
  y = v * sin(theta);
}

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel{
public:
  // TODO: Override the Move() function
  void Move(double v, double phi) override;
  // TODO: Define L
  double L{1};
};

void BicycleModel::Move(double v, double phi){
  theta += v / L * tan(phi);
  x = v * cos(theta);
  y = v * sin(theta);
}

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}