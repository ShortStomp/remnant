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
// Base class for all messages.
// 
//===----------------------------------------------------------------------===///
#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_

#include "move_message.hpp"
#include "acceleration_message.hpp"

namespace rem
{

  // enum declarations
  enum message_type {
    MESSAGE_TYPE_MOVE = 0,
    MESSAGE_TYPE_ACCELERATION,
  };

  // structure declarations
  struct message final
  {
    // members
   message_type Type;

    union {
     move_message Move_Message;
     acceleration_message Accelerate_Message;

   };

   // constructors
  message(const message_type type); 

  };
}

#endif // _MESSAGE_HPP_ definition
