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

namespace rem
{
  struct sprite_component :
    public icomponent
  {
    // members
    sf::Sprite Sprite;
    sf::Texture Texture;  // TODO: textures are heavy-weight and should not exist on each sprite_component
                          // but need to be managed else-where.

    // methods
    virtual void process_message(const message message) override;
  };
}
#endif