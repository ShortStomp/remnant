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
namespace rem
{

struct engine
{
  //
  // member variables
  sf::RenderWindow Window;

  //
  // constructor declarations
  engine(void);
};

}
#endif // _ENGINE_HPP_ definition