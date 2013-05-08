#include "icomponent.hpp"

//===----------------------------------------------------------------------===//
//
// The icomponent constructor initializes the Type and Parent_Ptr members.
//
//===----------------------------------------------------------------------===//
rem::icomponent::icomponent(const int component_type)
  : Component_Type(component_type),
  Parent_ptr(nullptr)
{

}