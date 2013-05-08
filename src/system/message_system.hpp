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
// The message system is responsible for processing message queue's on entities.
// As the game executes messages are given to entities. These messages are processed
// via the message system.
//
//===----------------------------------------------------------------------===///
#ifndef _MESSAGE_SYSTEM_HPP_ 
#define _MESSAGE_SYSTEM_HPP_

namespace rem
{
  // forward declarations
  struct engine;

namespace message_system
{
  void process_messages(rem::engine &engine);
}
}

#endif // _MESSAGE_SYSTEM_HPP_