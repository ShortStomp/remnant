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
// This component will be used to used to receive SMFL events and send
// the corresponding message TODO: Who does this send messages to?
// 
//===----------------------------------------------------------------------===///
#ifndef _INPUT_COMPONENT_HPP_
#define _INPUT_COMPONENT_HPP_
#include "icomponent.hpp"

namespace rem
{
  //forward declaration
  struct message;

  struct input_component :
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_INPUT;

    // constructors
    input_component(void) : icomponent(COMPONENT_TYPE) { }
  };
}
#endif // _INPUT_COMPONENT_HPP_ definition