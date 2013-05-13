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

namespace ec
{
  // forward declarations
  class entity;
  struct engine;
  struct transform_component;
  struct movement_component;

namespace movement_system
{
  void move_entities(ec::engine &engine);
}
}
#endif