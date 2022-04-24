#include <chrono>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <random>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */
 
template <typename T>
T MessageQueue<T>::receive()
{
    std::unique_lock<std::mutex> lck (_mtx);
    _condition.wait(lck, [this]{ return !_queue.empty();});

    T message = std::move(_queue.back());
    _queue.pop_back();
    std::cout << "Message Queue popped.\n";
    return message;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    std::lock_guard<std::mutex> lck (_mtx);
    _queue.push_back(std::move(msg)); 
    _condition.notify_one();
}


/* Implementation of class "TrafficLight" */

TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::kred;
}


void TrafficLight::waitForGreen()
{
    while (true) {
      if (_messages.receive()==TrafficLightPhase::kgreen){
        return;
      }
    }
}


TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate()
{
    threads.push_back(std::move(std::thread(&TrafficLight::cycleThroughPhases, this)));  
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    auto start = std::chrono::high_resolution_clock::now(); 
    int max_cycle_duration = rand() % 3 + 4;

    while (true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      auto now = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - start);

     
      if (duration.count() >= max_cycle_duration){ 
        if (_currentPhase == TrafficLightPhase::kred) {
          _currentPhase = TrafficLightPhase::kgreen;
        }
        else{
          _currentPhase = TrafficLightPhase::kred;
        }

        start = now;
        _messages.send(std::move(_currentPhase));     
      }


    }
}

