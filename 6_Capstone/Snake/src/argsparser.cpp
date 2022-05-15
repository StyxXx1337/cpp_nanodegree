#include "argsparser.h"

bool ArgParser::withWall(){
  for (auto arg : args_){
    if (arg == "-wall"){
      return true;
    }
  }
  return false;
}

bool ArgParser::withTreasures(){
  for (auto arg : args_){
    if (arg == "-treasure"){
      return true;
    }
  }
  return false;
}
