#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <vector>

#include "../include/linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

string LinuxParser::Kernel() {
  string os, kernel, version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

float LinuxParser::MemoryUtilization(){
  const std::string mem_total {"MemTotal:"};
  const std::string mem_free {"MemFree:"};

  std::string name, unit;
  double value {0};

  double total{0}, free{0};
  std::string line;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);

  while (stream.is_open()){
    std::getline(stream, line);
    std::istringstream iss {line};

    iss >> name >> value >> unit;

    if (name == mem_total){
      total = value;
    }
    else if(name == mem_free){
      free = value;
    }

    if (total > 0 && free >0){
      return (total - free) / total;
    }

  }

  return 0.0;
}

long LinuxParser::UpTime() {
  long upTime {0}, idleTime {0};

  std::ifstream stream(kProcDirectory + kUptimeFilename);

  if (stream.is_open()){
    stream >> upTime >> idleTime;
  }
  return upTime;
}

long LinuxParser::Jiffies() {
  auto cpuStr = LinuxParser::CpuUtilization();

  std::string tag;
  std::stringstream stream {cpuStr[0]};

  stream >> tag;

  long sum {0};
  long temp {0};

  while(!stream.eof()){
    stream >> temp;
    sum += temp;
  }
  return sum;
}

long LinuxParser::ActiveJiffies() {
    auto cpuStr = LinuxParser::CpuUtilization();

  std::string tag;
  // 10 Values of the CPU Line
  float usr {.0};
  float nice{.0};
  float system{.0};
  float idle {.0};
  float iowait{.0};
  float irq{.0};
  float sirq{.0};
  float steal{.0};
  float guest{.0};
  float guest_nice{.0};

  std::stringstream ss {cpuStr[0]};
  ss >> tag >> usr >> nice >> system
     >> idle >> iowait >> irq >> sirq
     >> steal >> guest >> guest_nice;

  float total {usr + nice + system + idle
          + iowait + irq + sirq + steal
          + guest + guest_nice};
  float tidle {idle + iowait};

  return (total - tidle);
}

long LinuxParser::IdleJiffies() {
  auto cpuStr = LinuxParser::CpuUtilization();

  std::string tag;
  // 10 Values of the CPU Line
  float usr {.0};
  float nice{.0};
  float system{.0};
  float idle {.0};
  float iowait{.0};
  float irq{.0};
  float sirq{.0};
  float steal{.0};
  float guest{.0};
  float guest_nice{.0};

  std::stringstream ss {cpuStr[0]};
  ss >> tag >> usr >> nice >> system
     >> idle >> iowait >> irq >> sirq
     >> steal >> guest >> guest_nice;

  return idle + iowait;
}

vector<string> LinuxParser::CpuUtilization() {

  const std::string cpuTag {"cpu"};

  vector<string> cpus;
  std::string line;

  std::ifstream stream {kProcDirectory + kStatFilename};

  while(stream.is_open()){
    getline(stream, line);
    if (line.find(cpuTag) != 0){
      break;
    }
    else{
      cpus.push_back(line);
    }
  }
  return cpus;
}

int LinuxParser::TotalProcesses() {
  const std::string tProcesses {"processes"};
  std::string key, line;
  long value;

  std::ifstream stream(kProcDirectory + kStatFilename);

  while (stream.is_open()){
    std::getline(stream, line);
    std::istringstream iss {line};

    iss >> key;

    if (key == tProcesses){
      iss >> value;
      return value;
    }
  }
  return 0;
}

int LinuxParser::RunningProcesses() {
  const std::string procRunning {"procs_running"};
  std::string key, line;
  long value;

  std::ifstream stream(kProcDirectory + kStatFilename);

  while (stream.is_open()){
    std::getline(stream, line);
    std::istringstream iss {line};

    iss >> key;

    if (key == procRunning){
      iss >> value;
      return value;
    }
  }
  return 0;
}

long LinuxParser::ActiveJiffies(int pid) {
  std::ifstream stream {kProcDirectory + to_string(pid) + kStatFilename};
  std::string line;

  long utime {0};
  long stime {0};
  long cutime {0};
  long cstime {0};

  if (stream.is_open()){
    getline(stream, line);
    std::string temp;
    std::stringstream ss {line};

    size_t counter = 1;
    while (counter < 14){
      ss >> temp;
      ++counter;
    }
    ss >> utime >> stime >> cutime >> cstime;
  }

  return utime + stime + cutime + cstime;
}

string LinuxParser::Command(int pid) {

  std::ifstream stream {kProcDirectory + std::to_string(pid) + kCmdlineFilename};
  std::string cmd;
  if (stream.is_open()){
    getline(stream, cmd);
  }

  return cmd;
}

string LinuxParser::Ram(int pid) {
  const std::string ramTag {"VmSize:"};

  std::ifstream stream {kProcDirectory + to_string(pid) + kStatusFilename};
  std::string tag;
  long ram{0};
  std::string line;

  while(!stream.eof()){
    getline(stream, line);
    std::stringstream ss {line};
    ss >> tag;

    if (tag == ramTag){
      ss >> ram;
      break;
    }
  }
  return to_string(ram / 1024); // Convert from KB to MB
}

string LinuxParser::Uid(int pid) {
  const std::string uidTag {"Uid:"};

  std::ifstream stream {kProcDirectory + to_string(pid) + kStatusFilename};
  std::string tag;
  std::string uid;

  while(stream.is_open()){
    stream >> tag;
    if (tag == uidTag){
      stream >> uid;
      break;
    }
  }
  return uid;
}

string LinuxParser::User(int pid) {
  std::string uid {LinuxParser::Uid(pid)};

  std::ifstream stream {kPasswordPath};
  std::string line;
  std::string usr, x, id;

  while(stream.is_open()){
    getline(stream, line);
    std::replace(line.begin(), line.end(), ':', ' ');

    std::stringstream ss {line};
    ss >> usr >> x >> id;
    if (id == uid){
      break;
    }

  }
  return usr;
}

long LinuxParser::UpTime(int pid) {
  std::ifstream stream {kProcDirectory + to_string(pid) + kStatFilename};
  std::string line;
  int hz = sysconf(_SC_CLK_TCK);
  long startTime {0};

  if (stream.is_open()){
    getline(stream, line);
    std::stringstream ss {line};
    std::string temp;

    size_t counter = 1;
    while (counter < 22){
      ss >> temp;
      ++counter;
    }
    ss >> startTime;
  }
  long systemUpTime = LinuxParser::UpTime();
  long processUpTime = systemUpTime - (startTime/hz);

  return processUpTime;
}