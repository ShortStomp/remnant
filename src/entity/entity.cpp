#include "entity.hpp"

rem::entity::entity(const rem::entity_id id)
  : _id(id)
{
}


void
rem::entity::add_component(
  rem::icomponent *const component_ptr
  )
{
  if(component_ptr == nullptr) {
    // TODO: pull in boost's logging mechanism so we can link to that library and log accordingly.
    //DEBUG_LOG_RUNTIME_ERROR("nullptr component_ptr passed to entity::add_component()");
    return;
  }

  // add the ptr to this entity
  _components.emplace_back(component_ptr);
}