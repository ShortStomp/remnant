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
// The graphics system is the system responsible for drawing everything onto the
// screen. The graphics system is a collection of free-standing functions, the graphics-
// system contains no state.
//
//===----------------------------------------------------------------------===///
namespace ec
{
  //
  // forward declarations
  struct engine;

namespace graphics_system
{
  void update_screen(ec::engine &engine);
}
}