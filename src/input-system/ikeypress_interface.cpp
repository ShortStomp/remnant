#include "ikeypress_interface.hpp"
#include "input_system.hpp"

//===----------------------------------------------------------------------===//
//
// TODO:
//
//===----------------------------------------------------------------------===///
ec::ikeypress_interface::ikeypress_interface(ec::input_system &input_system)
  : _input_system_handle(input_system.subscribe(this))
{

}


//===----------------------------------------------------------------------===//
//
// TODO:
//
//===----------------------------------------------------------------------===///
ec::ikeypress_interface::~ikeypress_interface(void)
{

}