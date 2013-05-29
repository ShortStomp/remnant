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

#include "..\observer_system\observer_system.hpp"
#include "sprite_group.hpp"
#include "..\tetris\tetris_block.hpp"
#include "..\tetris\movable_tetris_block.hpp"

namespace sf
{
  class Sprite;
}

namespace ec
{
  // forward declarations
  class entity;
  struct input_component;
  struct movement_component;
  struct gravity_component;

struct engine
{
  // member variables
  float                 Elapsed_Time;
  sf::RenderWindow      Window;
  obs::observer_system  Input_System;
  std::vector<entity*>  Entities;

  std::vector<tet::movable_tetris_block> MovableTetrisBlocks;
  std::vector<tet::tetris_block> TetrisBlocks;
  std::vector<ec::sprite_group> SpriteGroups;
};

}
#endif // _ENGINE_HPP_ definition