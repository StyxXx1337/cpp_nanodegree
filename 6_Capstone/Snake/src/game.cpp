#include "game.h"
#include <iostream>
#include "SDL.h"
#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height, bool withWall, bool withTreasures, bool withObjects, int speed)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      width(grid_width),
      height(grid_height),
      speed(speed){

  if (withWall){
    objects.createWall(grid_width, grid_height);
  }
  PlaceFood();
  if (withTreasures){
    treasure.setAlive(true);
  }
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, objects, treasure);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    bool already_occupied {false};
    // Check that the location is not occupied by a snake item before placing
    // food.

    for (auto const &object : objects.objects){
      if (object.x_ == x && object.y_ == y){
        already_occupied = true;
        break;
      }
    }

    if (!snake.SnakeCell(x, y) && !already_occupied) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::PlaceObject() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    bool already_occupied {false};
    
    // Check that the location is not occupied by a snake item before placing
    // the object

    for (auto const &object : objects.objects){
      if (object.x_ == x && object.y_ == y){
        already_occupied = true;
        break;
      }
    }

    if (!snake.SnakeCell(x, y) && !(food.x == x && food.y == y) && !already_occupied) {
      float speed_x = 0.0f;
      float speed_y = 0.0f;

      if (objects.objects.size() % 2 == 0){
        speed_x = speed * 0.02;
      }
      else{
        speed_y = speed * 0.02;
      }

      objects.objects.push_back(Object(x, y, speed_x, speed_y, GetGameHeight(), GetGameWidth()));
      return;
    }
  }
}

void Game::PlaceTreasure() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    bool already_occupied {false};
    
    // Check that the location is not occupied by a snake item before placing
    // the object

    for (auto const &object : objects.objects){
      if (object.x_ == x && object.y_ == y){
        already_occupied = true;
        break;
      }
    }

    if (!snake.SnakeCell(x, y) && !(food.x == x && food.y == y) && !already_occupied) {
      treasure.coordinate.x = x;
      treasure.coordinate.y = y;
      treasure.resetTiming();
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();
  for (auto &obj : objects.objects){
    obj.Update();
  }

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    if (score % 4 == 0){
      PlaceObject();
    }
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }

  if (objects.isThereAnObject(new_x, new_y) == true){
    snake.alive = false;
  }

  if (treasure.isTreasure(new_x, new_y)){
    if (treasure.totalTime != 0){
      score += 5;
      treasure.timing = 0;
      snake.GrowBody();
    }
  }
  if (treasure.totalTime == 0){
    PlaceTreasure();
  }
  treasure.Update();
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
int Game::GetGameWidth() const { return width; }
int Game::GetGameHeight() const { return height; }
int Game::GetSpeed() const { return speed; }
