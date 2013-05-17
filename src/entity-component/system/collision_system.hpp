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
// The graphics system is the system responsible for determining if the entity
// is colliding with anything.
//
//===----------------------------------------------------------------------===///
#ifndef _COLLISION_SYSTEM_HPP_
#define _COLLISION_SYSTEM_HPP_

namespace ec
{
namespace collision_system
{
  bool collision_detection(engine &engine, entity *const moving_entity_ptr);
}
}
#endif