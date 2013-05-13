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
#include <vector>
#include <SFML\Graphics\RenderWindow.hpp>

namespace ec
{
  // forward declarations
  class entity;
  struct input_component;
  struct sprite_component;
  struct movement_component;
  struct gravity_component;

struct engine
{
  //
  // member variables
  float                 Elapsed_Time;
  sf::RenderWindow      Window;

  std::vector<entity*>  Entities;
};

}
#endif // _ENGINE_HPP_ definition