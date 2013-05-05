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
// A small wrapper class for an integer that acts as a unique identifier
// for an entity. This class can only be instantiated via an entity_factory.
// Thus an entity can only be constructed via the entity_factory class which
// ensures that each entity will be constructed with a unique identifier.
//
//===----------------------------------------------------------------------===///
#ifndef _ENTITY_ID_HPP_
#define _ENTITY_ID_HPP_

namespace rem
{
  class entity_id
  {
    // forward declarations
    friend class entity_factory;

    // members
    const unsigned int _id;

    // constructors
    explicit entity_id(const unsigned int id);
    entity_id(void) /* = delete */;

  };
}
#endif _ENTITY_ID_HPP_ definition