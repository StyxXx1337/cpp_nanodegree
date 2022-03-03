#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
 public:
  Process(int pid, std::string command, std::string uid, std::string usr)
    : pid_(pid), command_(command),  uid_(uid), user_(usr){

      cpuUsg_ = CpuUtilization();
      upTime_ = UpTime();
  };

  int Pid();
  std::string User();
  std::string Command();
  float CpuUtilization();
  std::string Ram();
  long int UpTime();
  bool operator<(Process const& a) const;
  bool operator>(Process const& a) const;

 private:
  int pid_;
  std::string command_;
  std::string uid_;
  std::string user_;

  long upTime_ {1};
  float cpuUsg_ {.0};
};

#endif