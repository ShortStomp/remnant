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
#ifndef _MOVABLE_TETRIS_BLOCK_
#define _MOVABLE_TETRIS_BLOCK_
#include "tetris_block.hpp"
#include "../observer_system/iobserver.hpp"
namespace tet
{
  class movable_tetris_block :
    public tetris_block,
    public obs::iobserver
  {
    
  public:

    // constructors
    movable_tetris_block(obs::observer_system &observer_system);
    movable_tetris_block(const movable_tetris_block &other);
    movable_tetris_block(movable_tetris_block &&other);

    // destructor
    ~movable_tetris_block(void);

    // virtual method overrides
    virtual void on_notify(const sf::Keyboard::Key keycode) override;
  };
}
#endif // _MOVABLE_TETRIS_BLOCK_