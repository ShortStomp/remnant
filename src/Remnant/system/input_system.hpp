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
// The input_system is the system responsible for routing all user input to their correct
// components. The input system is a collection of free-standing functions, the input-
// system contains no state.
//
//===----------------------------------------------------------------------===///
#ifndef _INPUT_SYSTEM_HPP_
#define _INPUT_SYSTEM_HPP_

namespace rem
{
  //
  // forward declarations
  struct engine;

namespace input_system
{
  void process_input(rem::engine &engine, bool &game_finished);
}

}
#endif // _INPUT_SYSTEM_HPP_ definition