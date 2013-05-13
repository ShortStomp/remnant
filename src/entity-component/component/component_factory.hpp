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
// TODO: description
// 
//===----------------------------------------------------------------------===///
#ifndef _COMPONENT_FACTORY_HPP_
#define _COMPONENT_FACTORY_HPP_

namespace ec
{
  template<typename T>
  struct component_factory
  {
    // members
    T* get(void) const;
  };
}
#include "component_factory.inc"
#endif