#include "sprite_group.hpp"
#include <SFML\Graphics\RenderTarget.hpp>

////////////////////////////////////////////////////////////
void
ec::sprite_group::push_back(const sf::Sprite &sprite)
{
  _container.push_back(sprite);
}

////////////////////////////////////////////////////////////
void
ec::sprite_group::move(const sf::Vector2f &offset)
{
  _container.front().move(offset);
  for(auto &it : _container) {
    const auto a = it.getPosition();
    it.move(offset);
    const auto b = it.getPosition();
    __debugbreak();
  }
}


////////////////////////////////////////////////////////////
void
ec::sprite_group::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for(const auto &it : _container) {
    const auto combined_transform = getTransform() * it.getTransform();
    target.draw(it, combined_transform);
  }
}