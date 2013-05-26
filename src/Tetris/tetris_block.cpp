#include "tetris_block.hpp"
#include <SFML\Graphics\RenderTarget.hpp>

////////////////////////////////////////////////////////////////////////////////////
tet::tetris_block::tetris_block(void)
{
  const auto result = _texture.loadFromFile("../../assets/tetris-block.png");
  if(result == false) { __debugbreak(); }
}


////////////////////////////////////////////////////////////
void
tet::tetris_block::add_block(const sf::Vector2f &coord)
{
  sf::Sprite sprite;
  sprite.setTexture(_texture);
  sprite.move(coord.x, coord.y);

  _sprite_group.push_back(sprite);
}


////////////////////////////////////////////////////////////
void
tet::tetris_block::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_sprite_group);
}


////////////////////////////////////////////////////////////
//void
//tet::tetris_block::on_key_press(const sf::Keyboard::Key key)
//{
//__debugbreak();
//}