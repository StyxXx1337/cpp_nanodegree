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
/*You need to complete the mentioned TODOs in order to satisfy the rubric
criteria "The student will be able to extract and display basic data about the
system."

You need to properly format the uptime. Refer to the comments mentioned in
format. cpp for formatting the uptime.*/

System::System(){
  kernel_ = LinuxParser::Kernel();
  os_ = LinuxParser::OperatingSystem();

  auto pids {LinuxParser::Pids()};

  for (int pid : pids){
    std::string cmd = LinuxParser::Command(pid);
    std::string uid = LinuxParser::Uid(pid);
    std::string usr = LinuxParser::User(pid);

    processes_.emplace_back(Process(pid, cmd, uid, usr));
  }

}

// TODO: Return the system's CPU
Processor& System::Cpu() {
  return cpu_;
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() {

  std::sort(processes_.begin(), processes_.end(), std::greater<>());
  // std::reverse(processes_.begin(), processes_.end());

  return processes_;
}


std::string System::Kernel() {
    return kernel_;
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() {
  return LinuxParser::MemoryUtilization();
}

std::string System::OperatingSystem() {
  return os_;
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() {
  return LinuxParser::RunningProcesses();
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() {
  return LinuxParser::TotalProcesses();
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() {
  return LinuxParser::UpTime();
}
