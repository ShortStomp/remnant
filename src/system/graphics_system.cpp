//
// author: Benjamin Adamson and Wesley Kos
// TODO:
#include "..\engine.hpp"
#include "graphics_system.hpp"

void
rem::system::graphics_system::update_screen(rem::engine &engine)
{
  // clear the window with black color
  engine.Window.clear();

  // draw everything here

  // current frame ends here
  engine.Window.display();
}