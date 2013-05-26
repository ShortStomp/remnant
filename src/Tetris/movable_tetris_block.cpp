#include "movable_tetris_block.hpp"

////////////////////////////////////////////////////////////
tet::movable_tetris_block::movable_tetris_block(ec::input_system &input_system) : ikeypress_interface(input_system)
{

}

////////////////////////////////////////////////////////////
void
tet::movable_tetris_block::on_key_press(const sf::Keyboard::Key key)
{
  const auto delta = sf::Vector2f(1.03f, 2.03f);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    _sprite_group.move(delta);
  }
}