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
  class entity;
  struct input_component;
  struct sprite_component;

struct engine
{
  //
  // member variables
  sf::RenderWindow Window;
  std::vector<entity*> Entities;
  std::vector<input_component*> Input_Component;
  std::vector<sprite_component*> Sprite_Components;

  //
  // constructor declarations
  engine(void);
};

}
#endif // _ENGINE_HPP_ definition