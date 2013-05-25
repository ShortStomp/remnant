#include "../component/icomponent.hpp"
#include "entity.hpp"

//===----------------------------------------------------------------------===//
//
// the entity constructor, initializes the entity constant member variable id with
// the id passed into the constructor.
//
//===----------------------------------------------------------------------===//
ec::entity::entity(const ec::entity_id id)
  : _id(id),
  Parent(nullptr),
  _components(COMPONENT_TYPE_MAX, nullptr)
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

  // get a reference to the pointer inside _components where icomponent ptr should be
  auto &component_ptr_inside_vector = _components.at(component_ptr->Component_Type);

  if(component_ptr_inside_vector != nullptr) {
    // component type already added to this entity, error.
    //__debugbreak();
  }

  // set the components parent to the entity
  component_ptr->Entity_Pointer = this;

  // update the pointer inside _components
  component_ptr_inside_vector = component_ptr;
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
  const int component_type
  )
{
}