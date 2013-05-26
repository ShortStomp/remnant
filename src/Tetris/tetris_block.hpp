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
// The "concept" of a tetris block is represented by this class. TODO: document
//
//===----------------------------------------------------------------------===///
#ifndef _TETRIS_BLOCK_HPP_
#define _TETRIS_BLOCK_HPP_
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include "../entity-component/sprite_group.hpp"
namespace tet
{
  class tetris_block :
    public sf::Drawable
  {

  protected:
    // members
    ec::sprite_group _sprite_group;
    sf::Texture       _texture;

  public:

    // constructors
    tetris_block(void);

    // methods
    void add_block(const sf::Vector2f &coord);

    // virtual method overrides
    virtual void draw(sf::RenderTarget &target, sf::RenderStates render_state) const override;
  };
}
#endif // _TETRIS_BLOCK_HPP_