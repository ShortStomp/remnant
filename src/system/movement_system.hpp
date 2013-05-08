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
// The graphics system is the system responsible for drawing everything onto the
// screen. The graphics system is a collection of free-standing functions, the graphics-
// system contains no state.
//
//===----------------------------------------------------------------------===///
#ifndef _MOVEMENT_SYSTEM_HPP_
#define _MOVEMENT_SYSTEM_HPP_
#include "../messages/move_message.hpp"

namespace rem
{
  // forward declarations
  class entity;
  struct transform_component;
  struct movement_component;

namespace movement_system
{
  void move_entity(const movement_component &movement, transform_component &transform);
}
}
#endif