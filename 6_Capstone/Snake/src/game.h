#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "objects.h"
#include "renderer.h"
#include "snake.h"
#include "treasure.h"
#include <random>

class Game {
public:
  Game(std::size_t grid_width, std::size_t grid_height, bool withWall,
       bool withTreasures, bool withObjects, int speed);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  int GetGameHeight() const;
  int GetGameWidth() const;
  int GetSpeed() const;

private:
  Snake snake;
  SDL_Point food;
  Objects objects;
  Treasure treasure;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  int speed{0};
  int height;
  int width;
  bool withObjects{false};

  void PlaceFood();
  void Update();
  void PlaceObject();
  void PlaceTreasure();
};

#endif
