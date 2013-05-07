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
// 
//
//===----------------------------------------------------------------------===///

#ifndef _KEYPRESS_MESSAGE_
#define _KEYPRESS_MESSAGE_

#include <SFML\Window\Event.hpp>

namespace rem
{
  struct keypress_message
  {
    sf::Keyboard::Key Key;
  };
}
#endif // _KEYPRESS_MESSAGE_ definition