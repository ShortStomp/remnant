#include "..\entity-component\engine.hpp"
#include "game.hpp"

//===----------------------------------------------------------------------===//
//
// Entry point to the application. Simply initializes the engine and then passes 
// control to the game loop.
//
//===----------------------------------------------------------------------===///
int main(int argc, char *argv[])
{
  ec::engine engine_instance;

  tet::game::game_loop(engine_instance);

  return 0;
}