#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <condition_variable>
#include <vector>
#include <future>
#include <mutex>
#include <memory>
#include "TrafficLight.h"
#include "TrafficObject.h"

class Street;
class Vehicle;

class WaitingVehicles
{
public:
    int getSize();

    void pushBack(std::shared_ptr<Vehicle> vehicle, std::promise<void> &&promise);
    void permitEntryToFirstInQueue();

private:
    std::vector<std::shared_ptr<Vehicle>> _vehicles;
    std::vector<std::promise<void>> _promises; 
    std::mutex _mutex;
};

class Intersection : public TrafficObject
{
public:
    Intersection();

    void setIsBlocked(bool isBlocked);

    void addVehicleToQueue(std::shared_ptr<Vehicle> vehicle);
    void addStreet(std::shared_ptr<Street> street);
    std::vector<std::shared_ptr<Street>> queryStreets(std::shared_ptr<Street> incoming);
    void simulate();
    void vehicleHasLeft(std::shared_ptr<Vehicle> vehicle);
    bool trafficLightIsGreen();

private:
    void processVehicleQueue();

    std::vector<std::shared_ptr<Street>> _streets;
    WaitingVehicles _waitingVehicles; 
    TrafficLight _trafficLight;
    bool _isBlocked;                  
};

#endif
