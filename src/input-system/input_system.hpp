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
// The input_system is the system responsible for routing all user input to their correct
// components.
//
//===----------------------------------------------------------------------===///
#ifndef _INPUT_SYSTEM_HPP_
#define _INPUT_SYSTEM_HPP_
#include <map>

namespace sf
{
  class RenderWindow;
}
namespace ec
{
  //
  // forward declarations
  struct engine;
  class ikeypress_interface;

  // typedefinitions (should probably make this a unique type)
  typedef int handle_type;

  class input_system
  {
    // members
    //ec::engine                                  &_engine;
    std::map<ikeypress_interface*, handle_type> _input_map;

  public:

    // constructors
    //input_system(ec::engine &engine);

    // methods
   handle_type subscribe(ikeypress_interface *const subscribee);
   bool unsubscribe(const handle_type handle);

   void notify_subscribers(sf::RenderWindow &window);
  };

}
#endif // _INPUT_SYSTEM_HPP_ definition