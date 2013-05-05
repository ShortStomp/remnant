#include "engine.hpp"
#include "game.hpp"

//===----------------------------------------------------------------------===//
//
// Entry point to the application. Simply initializes the engine and then passes 
// control to the game loop.
//
//===----------------------------------------------------------------------===///
int main(int argc, char *argv[])
{
  rem::engine engine_instance;

  rem::game::game_loop(engine_instance);

  return 0;
}