#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
    float hz = sysconf(_SC_CLK_TCK);
    // if (upTime_ <= 0){
    //  cpuUsg_ = 0;
    // }
    // else{
      cpuUsg_ = ((LinuxParser::ActiveJiffies(pid_) / hz) / upTime_);
    // }
    return cpuUsg_;
}

// TODO: Return the command that generated this process
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {

    upTime_ = LinuxParser::UpTime(pid_);
    return upTime_;
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    return (this->cpuUsg_ < a.cpuUsg_);
}

bool Process::operator>(Process const& a) const {
    return (this->cpuUsg_ > a.cpuUsg_);
}