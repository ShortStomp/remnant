#include "movement_component.hpp"

//===----------------------------------------------------------------------===//
//
// movement_component constructor, initializes the Velocity and Acceleration
// members.
//
//===----------------------------------------------------------------------===//
rem::movement_component::movement_component(void) :
  icomponent(COMPONENT_TYPE),
  Velocity(0.0f, 0.0f),
  Acceleration(0.0f, 0.0f)
{

}