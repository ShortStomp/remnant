#include "sprite_group.hpp"
#include <SFML\Graphics\RenderTarget.hpp>

//===----------------------------------------------------------------------===//
//
// TODO: comment
//
//===----------------------------------------------------------------------===//
void
ec::sprite_group::push_back(const sf::Sprite &sprite)
{
  _container.push_back(sprite);
}


//===----------------------------------------------------------------------===//
//
// TODO: comment
//
//===----------------------------------------------------------------------===//
void
ec::sprite_group::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for(const auto it : _container) {
    const auto combined_transform = getTransform() * it.getTransform();
    target.draw(it, combined_transform);
  }
}