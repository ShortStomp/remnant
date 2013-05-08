#include "transform_component.hpp"

//===----------------------------------------------------------------------===//
//
// The transform_component's constructor initializes all the member variables
// to default values.
//
//===----------------------------------------------------------------------===//
rem::transform_component::transform_component(void)
  : Rotation(0.0f),
  Position(0.0f, 0.0f),
  Scale(1.0f, 1.0f)
{

}