#include "entity_id.hpp"

//===----------------------------------------------------------------------===//
//
// the entity_id constructor, initializes the member variable _id with the integer
// value passed in to the constructor.
//
//===----------------------------------------------------------------------===//
ec::entity_id::entity_id(const unsigned int id)
  : _id(id)
{

}