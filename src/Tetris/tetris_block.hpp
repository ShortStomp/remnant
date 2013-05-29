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
#include "../entity-component/sprite_group.hpp"
namespace tet
{
  class tetris_block :
    public ec::sprite_group
  {
    // members
    sf::Texture       _texture;

  public:

    // constructors
    tetris_block(void);
    tetris_block(const tetris_block &&other);
    tetris_block(tetris_block &&other) { __debugbreak(); }

    // destructor
    ~tetris_block(void) { }

    // methods
    void add_block(const sf::Vector2f &coord);
  };
}
#endif // _TETRIS_BLOCK_HPP_