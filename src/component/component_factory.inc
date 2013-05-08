#include "input_component.hpp"
#include "sprite_component.hpp"
#include "movement_component.hpp"

//===----------------------------------------------------------------------===//
//
// TODO: description
//
//===----------------------------------------------------------------------===//
template<typename T>
T*
rem::component_factory<T>::get(void) const
{
  // constuct a new component
  // forw now, we'll just use the heap. This should be super easy to switch out
  // with a pool based implementation, or something better.
  return new T();
}