#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "../include/linux_parser.h"
#include "../include/process.h"

using std::string;
using std::to_string;
using std::vector;

int Process::Pid() { return pid_; }

float Process::CpuUtilization() {
    float hz = sysconf(_SC_CLK_TCK);
    cpuUsg_ = ((LinuxParser::ActiveJiffies(pid_) / hz) / upTime_);

    return cpuUsg_;
}

string Process::Command() { return command_; }

string Process::Ram() { return LinuxParser::Ram(pid_); }

string Process::User() { return user_; }

long int Process::UpTime() {

    upTime_ = LinuxParser::UpTime(pid_);
    return upTime_;
}

bool Process::operator<(Process const& a) const {
    return (this->cpuUsg_ < a.cpuUsg_);
}

bool Process::operator>(Process const& a) const {
    return (this->cpuUsg_ > a.cpuUsg_);
}