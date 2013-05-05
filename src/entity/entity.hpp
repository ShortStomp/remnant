//
// author: Benjamin Adamson and Wesley Kos
// A unique identifier paired with a collection of components.
#ifndef _ENTITY_HPP
#define _ENTITY_HPP
#include <vector>
#include "entity_id.hpp"
namespace rem
{
  // forward declarations
  struct icomponent;
  struct transform_component;
  struct imessage;
  
  class entity
  {
    // friend declarations
    friend class entity_factory;

    // members
    const entity_id _id;
    transform_component *_transform_component;
    std::vector<icomponent*> _components;
    std::vector<imessage*> _messages;

    // constructors
    explicit entity(const entity_id id);

  public:

    // methods
    void add_component(icomponent *const component_ptr);
    void remove_component(void); // TODO: determine how this should work.
  };
}
#endif // _ENTITY_HPP definition