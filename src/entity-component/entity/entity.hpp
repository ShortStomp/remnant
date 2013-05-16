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
// This file defines the interface for an "entity." An entity can be thought of a
// unique identifier paired with a collection of components.
//
//===----------------------------------------------------------------------===//
#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_
#include <vector>
#include <queue>
#include "entity_id.hpp"
#include "..\messages\message.hpp"
#include "..\component\transform_component.hpp"
#include "entity_helpers.hpp"

namespace ec
{
  // forward declarations
  struct icomponent;

  class entity
  {
    // friend declarations
    friend class entity_factory;

    template<typename T>
    friend T* entity_helpers::get_component(entity *const entity_ptr);
    
    // members
    const entity_id _id;
    std::vector<icomponent*> _components;

    // constructors
    explicit entity(const entity_id id);

  public:
	
    // members
    entity              *Parent;
	  std::queue<message> Message_Queue;
    
	  // methods
    void add_component(icomponent *const component_ptr);
    void remove_component(const int component_type);
  };
}
#endif // _ENTITY_HPP_ definition