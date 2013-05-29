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
//
//===----------------------------------------------------------------------===///
#ifndef _OBSERVER_HANDLE_HPP_
#define _OBSERVER_HANDLE_HPP_
#include <boost\utility.hpp>
namespace obs
{
  // forward declarations
  class observer_system;
  class iobserver;

  enum { detached= -1 };

  class observer_handle
  {
    // friend declarations
    friend bool operator<(const obs::observer_handle &lhs, const obs::observer_handle &rhs);
    friend bool operator!=(const obs::observer_handle &lhs, const obs::observer_handle &rhs);
    friend class observer_system;

    // members
    int _value;

  public:

    // constructors
    explicit observer_handle(void);
    observer_handle(const observer_handle &other);
    observer_handle(observer_handle &&other);
  };

  // non member operators
  bool operator<(const obs::observer_handle &lhs, const obs::observer_handle &rhs);
  bool operator!=(const obs::observer_handle &lhs, const obs::observer_handle &rhs);
}
#endif // _OBSERVER_HANDLE_HPP_