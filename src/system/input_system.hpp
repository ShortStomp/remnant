//
// author: Benjamin Adamson and Wesley Kos
// TODO:
#ifndef _INPUT_SYSTEM_HPP_
#define _INPUT_SYSTEM_HPP_
// forward declarations
namespace rem
{
  //
  // forward declarations
  struct engine;

namespace system
{

namespace input_system
{
  void process_input(rem::engine &engine, bool &game_finished);
}

}
}
#endif // _INPUT_SYSTEM_HPP_ definition