#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <condition_variable>
#include <deque>
#include <memory>
#include <mutex>
#include <thread>
#include "TrafficObject.h"

class Vehicle;
enum TrafficLightPhase {
  kred,
  kgreen,
};

template <class T>
class MessageQueue
{
public:
    void send(T &&msg);
    T receive(void); 

private:
    std::deque<T> _queue;
    std::condition_variable _condition;
    std::mutex _mtx;
};

class TrafficLight : public TrafficObject
{
public:

    TrafficLight();

    TrafficLightPhase getCurrentPhase();

    void waitForGreen();
    void simulate();

private:
    void cycleThroughPhases();
    MessageQueue<TrafficLightPhase> _messages;
    std::condition_variable _condition;
    std::mutex _mutex;
    TrafficLightPhase _currentPhase;
};

#endif
