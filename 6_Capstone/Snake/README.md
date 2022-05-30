# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run basic game with: `./SnakeGame`.
  4.1 use `-wall` to add walls: `./SnakeGame -wall`
  4.2 use `-treasure` to add treasures: `./SnakeGame -treasure`
  4.3 use `-objects` to add objects and `-speed` to set their speed level (1-10)\ If speed is not given it is set to 0. `./SnakeGame -objects -speed 2`
  4.4 combine various options for your preferred game experience: `./SnakeGame -wall -treasure -objects -speed 5`

## Added features

1. [X] Added static objects that kill when you hit them
2. [X] Added Walls
3. [X] Add moving objects that kill you when you hit them
4. [X] Add special fruits that disappear after certain time again

## Known issues

1. Moving Objects crash into snake will not cause the game to finish (will not change)

## Folder Structure
```
Snake
| CMakeLists.txt
| CODEOWNERS
| README.md
| LICENSE.md
| snake_game.gif
|
└─── src
|    |  argsparser.cpp
|    |  argsparser.h
|    |  controller.cpp
|    |  controller.h
|    |  game.cpp
|    |  game.h
|    |  main.cpp
|    |  objects.cpp
|    |  objects.h
|    |  renderer.cpp
|    |  renderer.h
|    |  snake.cpp
|    |  snake.h
|    |  treasure.cpp
|    |  treasure.h
|
└─── build
|    ... // files build automatically
|
└─── cmake
|    | FindSDL2_image.cmake
|
```

## Object Structure

The `main.cpp` function calls the `ArgsParser` to read in the game options from the user.
With the arguments received by the `ArgParser` the main function first initiates a `Renderer` to show the basic game window.
After that creates a `Controller` to read the key strokes from the user.
Then the main function creates a `Game` instance and initalizes it. After that is calls the `Game::Run` function and hands over the controller and renderer to the main game loop. 

When `Game` is initialzed it creates a `Snake` instance and `Object` instances if required depending on the user input.
Also it defines the first food location and sets private variables like objects and treasure states.

`Game::Run` runs the main loop and deals with the controller input. Calls the `Game::Update` method to evaluate the input and update the game states accordingly. After the `Game` has updated the render object takes care of the visualization to the user.
 
The `Game::Update` method checks if the `Snake` has crashed and the game should be ended. Otherwise it updates the `Snake` and updates the `Objects` and the `Treasures` if required.


## Covered Project Rubics of Udacity Project:

### README (All Rubric Points REQUIRED)
#### A README with instructions is included with the project
[X] README is included with the project and has instructions for building/running the project.\
[X] If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions.\
[X] You can submit your writeup as markdown or pdf.\

#### The README indicates which project is chosen.
[X] The README describes the project you have built.\
[X] The README also indicates the file and class structure, along with the expected behavior or output of the program.

#### The README includes information about each rubric point addressed.
[X] The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.

### Compiling and Testing (All Rubric Points REQUIRED)
#### The submission must compile and run.
[X] The project code must compile and run without errors.\
[X] We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must compile on any reviewer platform.

### Loops, Functions, I/O
#### The project demonstrates an understanding of C++ functions and control structures.
[X] A variety of control structures are used in the project.\
[X] The project code is clearly organized into functions.\

#### The project reads data from a file and process the data, or the program writes data to a file.
[ ] The project reads data from an external file or writes data to a file as part of the necessary operation of the program.

#### The project accepts user input and processes the input.
[X] The project accepts input from a user as part of the necessary operation of the program.

### Object Oriented Programming
#### The project uses Object Oriented Programming techniques.
[X] The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.

#### Classes use appropriate access specifiers for class members.
[X] All class data members are explicitly specified as public, protected, or private.

#### Class constructors utilize member initialization lists.
[X] All class members that are set to argument values are initialized through member initialization lists.

#### Classes abstract implementation details from their interfaces.
[X] All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.

#### Classes encapsulate behavior.
[X] Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.

#### Classes follow an appropriate inheritance hierarchy.
[X] Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.

#### Overloaded functions allow the same function to operate on different parameters.
[X] One function is overloaded with different signatures for the same function name.

#### Derived class functions override virtual base class functions.
[ ] One member function in an inherited class overrides a virtual base class member function.

#### Templates generalize functions in the project.
[ ] One function is declared with a template that allows it to accept a generic parameter.

### Memory Management
#### The project makes use of references in function declarations.
[X] At least two variables are defined as references, or two functions use pass-by-reference in the project code.

#### The project uses destructors appropriately.
[X] At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.

#### The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
[ ] The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.

#### The project follows the Rule of 5.
[ ] For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.

#### The project uses move semantics to move data, instead of copying it, where possible.
[ ] For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object.

#### The project uses smart pointers instead of raw pointers.
[ ] The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.

### Concurrency [ Not Used ]
#### The project uses multithreading.
[ ] The project uses multiple threads in the execution.

#### A promise and future is used in the project.
[ ] A promise and future is used to pass data from a worker thread to a parent thread in the project code.

#### A mutex or lock is used in the project.
[ ] A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code.

#### A condition variable is used in the project.
[ ] A `std::condition_variable` is used in the project code to synchronize thread execution.



## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
