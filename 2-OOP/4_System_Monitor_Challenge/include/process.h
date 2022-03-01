#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid, std::string command, std::string uid, std::string usr)
    : pid_(pid), command_(command),  uid_(uid), user_(usr){

      cpuUsg_ = CpuUtilization();
      upTime_ = UpTime();
  };

  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  bool operator>(Process const& a) const;

  // TODO: Declare any necessary private members
 private:
  int pid_;
  std::string command_;
  std::string uid_;
  std::string user_;

  long upTime_ {1};
  float cpuUsg_ {.0};
};

#endif