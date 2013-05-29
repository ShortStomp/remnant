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
// TODO: comment
//
//===----------------------------------------------------------------------===//
#ifndef _SPRITE_GROUP_HPP_
#define _SPRITE_GROUP_HPP_
#include <vector>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Transformable.hpp>
namespace ec
{
  class sprite_group :
    public sf::Drawable,
    public sf::Transformable
  {
    // members
    std::vector<sf::Sprite> _container;

  public:

    // methods
    void push_back(const sf::Sprite &sprite);

    // virtual overloads
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  };
}
#endif // _SPRITE_GROUP_HPP_