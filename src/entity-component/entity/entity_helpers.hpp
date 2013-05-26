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
// Collection of non-member entity functions.
//
//===----------------------------------------------------------------------===//
#ifndef _ENTITY_HELPERS_HPP_
#define _ENTITY_HELPERS_HPP_
namespace ec
{
  // forward declarations
  class entity;
  struct input_component;
  struct movement_component;
  //struct sprite_component;
  struct transform_component;
  struct collision_component;

namespace entity_helpers
{
  // function declarations
  transform_component*  get_transform_component(entity *const entity_ptr);
  input_component*      get_input_component(entity *const entity_ptr);
  movement_component*   get_movement_component(entity *const entity_ptr);
  //sprite_component*     get_sprite_component(entity *const entity_ptr);
  collision_component*  get_collision_component(entity *const entity_ptr);

  // templated function declarations
  template<typename T>
  T* get_component(entity *const entity_ptr);
}
}
#include "entity_helpers.inc"
#endif