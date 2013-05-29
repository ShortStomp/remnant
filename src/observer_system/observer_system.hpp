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
// TODO: what does this system do??
//
//===----------------------------------------------------------------------===///
#ifndef _OBSERVER_SYSTEM_HPP_
#define _OBSERVER_SYSTEM_HPP_
#include <map>
#include "observer_handle.hpp"
#include <SFML\Window\Keyboard.hpp>

namespace sf
{
  class RenderWindow;
}
namespace obs
{
  //
  // forward declarations
  struct engine;
  class iobserver;

  // class declaration
  class observer_system
  {
    // members
    int                           _handle_counter;
    std::map<observer_handle, iobserver*> _observers;

  public:

    // constructors
    observer_system(void);

    // methods
   observer_handle subscribe(iobserver *const observer_ptr);
   void unsubscribe(const observer_handle handle);

   void notify_subscribers(sf::RenderWindow &window);
  };

  // nonmember functions
  bool move_handle(obs::observer_system &system, const observer_handle handle, iobserver *const observer_ptr);

} // obs namespace
#endif // _OBSERVER_SYSTEM_HPP_ definition