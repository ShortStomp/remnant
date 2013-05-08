#include "..\engine.hpp"
#include "..\component\sprite_component.hpp"
#include "..\entity\entity.hpp"
#include "graphics_system.hpp"

//===----------------------------------------------------------------------===//
//
// The function update_screen() is responsible for drawing the screen within the
// window.
//
//===----------------------------------------------------------------------===//
void
rem::graphics_system::update_screen(rem::engine &engine)
{
  // clear the window with black color
  engine.Window.clear();

  // draw everything here
  for(const auto it : engine.Sprite_Components) {
    it->Sprite.setPosition(it->Parent_ptr->Transform.getPosition());
    it->Sprite.setRotation(it->Parent_ptr->Transform.getRotation());
    it->Sprite.setScale(it->Parent_ptr->Transform.getScale());
    engine.Window.draw(it->Sprite);
  }

  // current frame ends here
  engine.Window.display();
}