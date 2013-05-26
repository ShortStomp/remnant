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
// TODO:
//
//===----------------------------------------------------------------------===///
#ifndef _IKEYPRESS_INTERFACE_HPP_
#define _IKEYPRESS_INTERFACE_HPP_
#include <SFML\Window\Keyboard.hpp>
namespace ec
{
  // forward declarations
  class input_system;

  // typedefinitions (remove this, duplicate definition in ikeypress_interface)
  typedef int handle_type;

  class ikeypress_interface
  {
    handle_type _input_system_handle;

  public:

    // constructors
    ikeypress_interface(ec::input_system &input_system);

    // pure virtual destructor
    virtual ~ikeypress_interface();

    // pure virtual methods
    virtual void on_key_press(const sf::Keyboard::Key keycode) = 0;

  };
}
#endif // _IKEYPRESS_INTERFACE_HPP_