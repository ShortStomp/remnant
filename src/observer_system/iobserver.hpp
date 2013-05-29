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
#ifndef _IOBSERVER_HPP_
#define _IOBSERVER_HPP_
#include <boost\utility.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "observer_handle.hpp"
namespace obs
{
  // class declaration
  class iobserver :
    private boost::noncopyable
  {
  protected:
    // members
    obs::observer_handle              _handle;
    obs::observer_system   &_observer_system;

  public:

    // constructors
    iobserver(observer_system &observer);
    iobserver(iobserver &&other);


    // pure virtual destructor
    virtual ~iobserver();

    // pure virtual methods
    virtual void on_notify(const sf::Keyboard::Key keycode) = 0;

  };
}
#endif // _IOBSERVER_HPP_