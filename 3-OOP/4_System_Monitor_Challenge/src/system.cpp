#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

System::System(){
  kernel_ = LinuxParser::Kernel();
  os_ = LinuxParser::OperatingSystem();
}

Processor& System::Cpu() {
  return cpu_;
}

vector<Process>& System::Processes() {

  auto pids = LinuxParser::Pids();

  // clear the vector not avoid dublicates
  processes_.clear();
  for (int pid : pids){
    std::string cmd = LinuxParser::Command(pid);
    std::string uid = LinuxParser::Uid(pid);
    std::string usr = LinuxParser::User(pid);

    processes_.emplace_back(Process(pid, cmd, uid, usr));
  }

  std::sort(processes_.begin(), processes_.end(), std::greater<>());

  return processes_;
}


std::string System::Kernel() {
    return kernel_;
}

float System::MemoryUtilization() {
  return LinuxParser::MemoryUtilization();
}

std::string System::OperatingSystem() {
  return os_;
}

int System::RunningProcesses() {
  return LinuxParser::RunningProcesses();
}

int System::TotalProcesses() {
  return LinuxParser::TotalProcesses();
}

long int System::UpTime() {
  return LinuxParser::UpTime();
}
