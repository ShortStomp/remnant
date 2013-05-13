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
// The sprite_component wraps an sf::Sprite to work our entity/component
// model.
//
//===----------------------------------------------------------------------===//
#ifndef _SPRITE_COMPONENT_HPP_
#define _SPRITE_COMPONENT_HPP_
#include "icomponent.hpp"
#include <SFML\Graphics\Sprite.hpp>

// TODO: this header include should go away when we move the conrete sf::Texture out of this class.
#include <SFML\Graphics\Texture.hpp>

namespace ec
{
  struct sprite_component :
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_SPRITE;

    // members
    sf::Sprite Sprite;
    sf::Texture Texture;  // TODO: textures are heavy-weight and should not exist on each sprite_component
                          // but need to be managed else-where.

    // constructors
    sprite_component(void) : icomponent(COMPONENT_TYPE) { }
  };

  
}
#endif