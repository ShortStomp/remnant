#include <utility>
#include "message.hpp"

//===----------------------------------------------------------------------===//
//
// Initializing the type member varible.
//
//===----------------------------------------------------------------------===//
ec::message::message(const message_type type) : Type(type)
{
  memset(&Move_Message, 0, sizeof(Move_Message));
} 