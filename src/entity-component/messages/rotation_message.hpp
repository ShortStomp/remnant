
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
// Message containing rotational change.
//
//===----------------------------------------------------------------------===///

#ifndef _ROTATION_MESSAGE_HPP
#define _ROTATION_MESSAGE_HPP
#include <SFML\System\Vector2.hpp>

namespace ec
{
  struct rotation_message
  {
    // members
    float Angle;    
  };
}
#endif // _ROTATION_MESSAGE_HPP