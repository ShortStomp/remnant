#include "..\engine.hpp"
#include "graphics_system.hpp"

//===----------------------------------------------------------------------===//
//
// The function update_screen() is responsible for drawing the screen within the
// window.
//
//===----------------------------------------------------------------------===//
void
rem::system::graphics_system::update_screen(rem::engine &engine)
{
  // clear the window with black color
  engine.Window.clear();

  // draw everything here

  // current frame ends here
  engine.Window.display();
}