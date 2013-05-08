#include <algorithm>
#include "../component/icomponent.hpp"
#include "../component/input_component.hpp"
#include "../component/movement_component.hpp"
#include "../component/sprite_component.hpp"

//===----------------------------------------------------------------------===//
//
// TODO: document
//
//===----------------------------------------------------------------------===//
inline rem::input_component*
rem::entity_helpers::get_input_component(entity *const entity_ptr)
{
  return get_component<input_component>(entity_ptr);
}


//===----------------------------------------------------------------------===//
//
// TODO: document
//
//===----------------------------------------------------------------------===//
inline rem::movement_component*
rem::entity_helpers::get_movement_component(entity *const entity_ptr)
{
  return get_component<movement_component>(entity_ptr);
}


//===----------------------------------------------------------------------===//
//
// TODO: document
//
//===----------------------------------------------------------------------===//
inline rem::sprite_component*
rem::entity_helpers::get_sprite_component(entity *const entity_ptr)
{
  return get_component<sprite_component>(entity_ptr);
}


//===----------------------------------------------------------------------===//
//
// TODO: document
//
//===----------------------------------------------------------------------===//
template<typename T>
T*
rem::entity_helpers::get_component(rem::entity *const entity_ptr)
{
   T *component_ptr = nullptr;

  const auto find_predicate = [=](const icomponent *const component_ptr) { return component_ptr->Component_Type== T::COMPONENT_TYPE; };
  const auto &components = entity_ptr->_components; // convenient alias

  const auto it = std::find_if(components.cbegin(), components.cend(), find_predicate);

  if(it != components.cend()) {
    component_ptr = static_cast<T*>(*it); // we found the component
  }
  return component_ptr;
}