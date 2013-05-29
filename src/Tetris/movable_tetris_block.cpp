#include "..\observer_system\observer_system.hpp"
#include "movable_tetris_block.hpp"

////////////////////////////////////////////////////////////
tet::movable_tetris_block::movable_tetris_block(obs::observer_system &observer_system)
  : iobserver(observer_system)
{

}


////////////////////////////////////////////////////////////
/*tet::movable_tetris_block::movable_tetris_block(const tet::movable_tetris_block &other)
  : ikeypress_interface(other)
{

}*/


////////////////////////////////////////////////////////////
tet::movable_tetris_block::movable_tetris_block(tet::movable_tetris_block &&other)
  : iobserver(std::move(other))
{

}


////////////////////////////////////////////////////////////
tet::movable_tetris_block::~movable_tetris_block(void)
{

}


////////////////////////////////////////////////////////////
void
tet::movable_tetris_block::on_notify(const sf::Keyboard::Key key)
{
  const auto delta = sf::Vector2f(1.03f, 2.03f);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    move(delta);
  }
}
