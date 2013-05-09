#include <algorithm>
#include "../component/icomponent.hpp"
#include "../component/input_component.hpp"
#include "../component/movement_component.hpp"
#include "../component/sprite_component.hpp"


//===----------------------------------------------------------------------===//
//
// Searches the entity's components for the component of type T. Returns a pointer
// to the component or a nullptr.
//
//===----------------------------------------------------------------------===//
template<typename T>
T*
ec::entity_helpers::get_component(ec::entity *const entity_ptr)
{
   T *component_ptr = nullptr;

   if(entity_ptr == nullptr) { // a null entity has no components
     return component_ptr;
   }

  const auto find_predicate = [=](const icomponent *const component_ptr) { return component_ptr->Component_Type == T::COMPONENT_TYPE; };
  const auto &components = entity_ptr->_components; // convenient alias

  const auto it = std::find_if(components.cbegin(), components.cend(), find_predicate);

  if(it != components.cend()) {
    component_ptr = static_cast<T*>(*it); // we found the component
  }
  return component_ptr;
}


//===----------------------------------------------------------------------===//
//
// Wrapper for getting the input_component from an entity.
//
//===----------------------------------------------------------------------===//
inline ec::input_component*
ec::entity_helpers::get_input_component(entity *const entity_ptr)
{
  return get_component<input_component>(entity_ptr);
}


//===----------------------------------------------------------------------===//
//
//
// Wrapper for getting the movement_component from an entity.
//
//===----------------------------------------------------------------------===//
inline ec::movement_component*
ec::entity_helpers::get_movement_component(entity *const entity_ptr)
{
  return get_component<movement_component>(entity_ptr);
}


//===----------------------------------------------------------------------===//
// 
// Wrapper for getting the sprite_component from an entity. 
//
//===----------------------------------------------------------------------===//
inline ec::sprite_component*
ec::entity_helpers::get_sprite_component(entity *const entity_ptr)
{
  return get_component<sprite_component>(entity_ptr);
}