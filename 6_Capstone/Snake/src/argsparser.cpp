#include "argsparser.h"
#include <cstddef>
#include <iostream>
#include <string>

bool ArgParser::withWall() {
  for (auto arg : args_) {
    if (arg == "-wall") {
      return true;
    }
  }
  return false;
}

bool ArgParser::withTreasures() {
  for (auto arg : args_) {
    if (arg == "-treasure") {
      return true;
    }
  }
  return false;
}

bool ArgParser::withObjects(){
  return false;
}

void ArgParser::PrintArgs(){
  int counter {0};
  for (auto arg : args_) {
    std::cout << "Counter" << counter << "\t" << arg << "\n";
    counter++;
  }
}

int ArgParser::getSpeed(){
   for (std::size_t i = 1; i < args_.size(); i++){
    if (args_[i] == "-speed"){
        try{
          int temp = std::stoi(args_[i+1]);
          if (temp > 0 && temp <=10){
            std::cout << "Speed set to: " << temp << "\n";
            return temp;
          }
        }
        catch (...){
          std::cerr << "Couln't cast the speed value\n";
        }
      }
    }
  return 0;
}

