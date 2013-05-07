//===-----------------------------------------------------------------------===//
//
//                     The Remnant Source code
//
// Authors:
//
//    Benjamin Adamson (adamson.benjamin@gmail.com)
//    Wesley Kos (kos.wesley@gmail.com)
//
//===----------------------------------------------------------------------===//
//
// The primary data-structure used throughout the game. Contains data-structures
// needed throughout the game.
//
//===----------------------------------------------------------------------===///
#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_
#include <SFML\Graphics\RenderWindow.hpp>
#include <vector>
//#include "entity\entity.hpp"

namespace rem
{
  // forward declarations
  struct input_component;
  class entity;

struct engine
{
  //
  // member variables
  sf::RenderWindow Window;
  std::vector<entity*> Entities;
  std::vector<input_component*> Input_Component;

  //
  // constructor declarations
  engine(void);
};

}
#endif // _ENGINE_HPP_ definition