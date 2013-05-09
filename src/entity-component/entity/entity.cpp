#include "../component/icomponent.hpp"
#include "entity.hpp"

//===----------------------------------------------------------------------===//
//
// the entity constructor, initializes the entity constant member variable id with
// the id passed into the constructor.
//
//===----------------------------------------------------------------------===//
ec::entity::entity(const ec::entity_id id)
  : _id(id)
{
}


//===----------------------------------------------------------------------===//
//
// the member function add_component() verifies the pointer passed into the function
// is not nullptr, and then adds the component to the entity's internal collection of
// component pointers.
//
//===----------------------------------------------------------------------===//
void
ec::entity::add_component(
  ec::icomponent *const component_ptr
  )
{
  if(component_ptr == nullptr) {
    // TODO: pull in boost's logging mechanism so we can link to that library and log accordingly.
    //DEBUG_LOG_RUNTIME_ERROR("nullptr component_ptr passed to entity::add_component()");
    return;
  }

  // set the components parent to the entity
  component_ptr->Entity_Pointer = this;

  // add the ptr to this entity
  _components.emplace_back(component_ptr);
}


//===----------------------------------------------------------------------===//
//
// Remves the component from the entity.
// TODO: flush out this method, currently we need to decide if we take a pointer
// to a component, or an containing it's type.
//
//===----------------------------------------------------------------------===//
void
ec::entity::remove_component(
  void
  )
{
}