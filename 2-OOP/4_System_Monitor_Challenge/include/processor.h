#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

class Processor {
 public:
  Processor(); // TODO: Make a initializer to save the amount of cpus
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  float usg {0};
  int nCpus {0};
  long preIdle {0};
  long preTotal {0};
};

#endif