#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

class Processor {
 public:
  Processor();
  float Utilization();

 private:
  float usg {0};
  int nCpus {0};
  long preIdle {0};
  long preTotal {0};
};

#endif