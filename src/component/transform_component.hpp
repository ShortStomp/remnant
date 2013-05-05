//
// author: Benjamin Adamson and Wesley Kos
// TODO:
#ifndef _TRANSFORM_COMPONENT_HPP_
#define _TRANSFORM_COMPONENT_HPP_
#include "icomponent.hpp"
namespace rem
{
  struct transform_component :
    public icomponent
  {
    // members
    float Rotation;
    float Position;
    float Scale;

    // constructors
    transform_component(void);
  };
}
#endif // _TRANSFORM_COMPONENT_HPP_