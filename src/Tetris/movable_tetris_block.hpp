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
// TODO: document
//
//===----------------------------------------------------------------------===///
#ifndef _MOVABLE_TETRIS_BLOCK
#define _MOVABLE_TETRIS_BLOCK
#include "tetris_block.hpp"
#include "../input-system/ikeypress_interface.hpp"
namespace tet
{
  class movable_tetris_block :
    public tetris_block,
    public ec::ikeypress_interface
  {
    
  public:

    // constructors
    movable_tetris_block(ec::input_system &input_system);

    // virtual method overrides
    virtual void on_key_press(const sf::Keyboard::Key keycode) override;
  };
}
#endif