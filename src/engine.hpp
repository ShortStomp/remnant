//
// author: Benjamin Adamson and Wesley Kos
// Entry point to the application. Simply initializes the engine and then passes 
// control to the game loop.
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