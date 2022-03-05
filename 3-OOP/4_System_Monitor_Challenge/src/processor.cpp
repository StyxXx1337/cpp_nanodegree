#include "linux_parser.h"
#include "processor.h"

Processor::Processor(){
  nCpus = LinuxParser::CpuUtilization().size() - 1;
}

float Processor::Utilization() {
  long total {LinuxParser::Jiffies()};
  long idle {LinuxParser::IdleJiffies()};

  // Calculate difference to previous measurement
  long dTotal = total - preTotal;
  long dIdle = idle - preIdle;

  float usg = (float)(dTotal - dIdle) / (float)dTotal;

  // Save for next itteration
  preIdle = idle;
  preTotal = total;

  return usg;
}