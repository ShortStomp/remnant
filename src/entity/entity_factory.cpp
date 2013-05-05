#include "entity.hpp"
#include "entity_factory.hpp"
#include "entity_id.hpp"

// initialize our static member variable
decltype(rem::entity_factory::_id_counter) rem::entity_factory::_id_counter = 1U;

rem::entity_factory::entity_factory(void)
{
  using namespace rem;

  // retrieve the unique id we will use when constructing the entity
  const entity_id entity_id(_id_counter);

  // increment the internal counter
  ++_id_counter;

  // create the entity using our unique id
  entity entity_instance(entity_id);
}