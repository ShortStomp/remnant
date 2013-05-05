//
// author: Benjamin Adamson and Wesley Kos
// The base class for every component that exists within the engine.
#ifndef _ICOMPONENT_HPP_
#define _ICOMPONENT_HPP_
namespace rem
{
  // forward declarations
  class entity;

  struct icomponent
  {
    // members
    entity *Parent_ptr;

    // constructors
    icomponent(void);
  };
}
#endif