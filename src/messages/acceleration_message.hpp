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
// Message containing a acceleration change data.
//
//===----------------------------------------------------------------------===///

#ifndef _ACCELERATION_MESSAGE_HPP_
#define _ACCELERATION_MESSAGE_HPP_
#include <SFML\System\Vector2.hpp>

namespace rem
{
  struct acceleration_message
  {
    // members
    float X_Acceleration;
    float Y_Acceleration;
  };
}
#endif // _ACCELERATION_MESSAGE_HPP_