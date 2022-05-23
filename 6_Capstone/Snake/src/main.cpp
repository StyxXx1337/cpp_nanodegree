#include "argsparser.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <cstddef>
#include <iostream>

int main(int argc, char **argv) {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  std::vector<std::string> args;

  for (size_t i = 0; i < argc; ++i) {
    args.emplace_back(argv[i]);
  }

  ArgParser argParser(std::move(args));
  argParser.PrintArgs();
  auto withWall = argParser.withWall();
  auto withTreasures = argParser.withTreasures();
  auto speed = argParser.getSpeed();
  auto withObjects = argParser.withObjects();

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, withWall, withTreasures, withObjects,
            speed);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
