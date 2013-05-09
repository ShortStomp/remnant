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
// The gravity system is responsible for producing movement messages for entities 
// that should be effected by gravity.
//
//===----------------------------------------------------------------------===///
#ifndef _GRAVITY_SYSTEM_HPP_
#define _GRAVITY_SYSTEM_HPP_
namespace rem
{
  // forward declarations
  struct engine;

  
  namespace gravity_system
  {
    // static const definitions
    static const auto GRAVITATIONAL_CONSTANT = 0.05f;

    // function definitions
    void apply_gravitational_forces(engine &engine);
  }
}
#endif // _GRAVITY_SYSTEM_HPP_