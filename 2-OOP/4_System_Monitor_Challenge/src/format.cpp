#include "format.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using std::string;

string Format::ElapsedTime(long seconds) {
  int hh{0};
  int mm{0};

  hh = seconds / 3600;
  seconds -= (hh * 3600);
  mm = seconds / 60;
  seconds -= (mm * 60);

  std::stringstream ss;

  ss << std::setw(2) << std::setfill('0') << hh << ':'
     << std::setw(2) << std::setfill('0') << mm << ':'
     << std::setw(2) << std::setfill('0') << seconds;

  return ss.str();
}