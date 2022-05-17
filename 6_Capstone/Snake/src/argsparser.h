#ifndef ARGPARSER_H_
#define ARGPARSER_H_

#include <string>
#include <vector>

class ArgParser {
public:
  ArgParser(std::vector<std::string> &&args) : args_(args){};
  bool withWall(void);
  bool withTreasures(void);

private:
  std::vector<std::string> args_;
};

#endif
