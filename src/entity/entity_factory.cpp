#include "entity.hpp"
#include "entity_factory.hpp"
#include "entity_id.hpp"

// initialize our static member variable
decltype(rem::entity_factory::_id_counter) rem::entity_factory::_id_counter = 1U;


//===----------------------------------------------------------------------===//
//
// the member function get() gets a unique id using the static internal _id_counter member
// of the entity_factory class. With this id the entity is constructed and returned.
//
//===----------------------------------------------------------------------===//
rem::entity
rem::entity_factory::get(void) const
{
  using namespace rem;

  // retrieve the unique id we will use when constructing the entity
  const entity_id entity_id(_id_counter);

  // increment the internal counter
  ++_id_counter;

  // create the entity using our unique id
  entity entity_instance(entity_id);

  // TODO: Added this so it would run.
  return entity_instance;
}