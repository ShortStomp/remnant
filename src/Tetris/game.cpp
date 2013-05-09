#include <SFML\Window\Event.hpp>
#include "..\entity-component\\engine.hpp"
#include "..\entity-component\system\message_system.hpp"
#include "..\entity-component\system\input_system.hpp"
#include "..\entity-component\system\movement_system.hpp"
#include "..\entity-component\system\graphics_system.hpp"
#include "..\entity-component\system\gravity_system.hpp"
#include "..\entity-component\entity\entity_factory.hpp"
#include "..\entity-component\component\component_factory.hpp"
#include "game.hpp"


void
setup_test_code(ec::engine &engine)
{
  using namespace ec;

  // TEST CODE: Following code is for testing purposes only (referencing entiy_factory and input_component)
  entity_factory efactory;
  auto entity_instance = efactory.get();

  component_factory<input_component> input_cfactory;
  
  auto inputcomponent_ptr = input_cfactory.get();
  entity_instance->add_component(inputcomponent_ptr);
  engine.Entities.emplace_back(entity_instance);

  engine.Input_Component.emplace_back(inputcomponent_ptr);

  component_factory<movement_component> move_cfactory;

  auto move_component_ptr = move_cfactory.get();
  move_component_ptr->Velocity.x = 0.2f;
  move_component_ptr->Velocity.y = 0.1f;
  move_component_ptr->Acceleration.x = 0.0f;
  move_component_ptr->Acceleration.y = 0.0f;
  entity_instance->add_component(move_component_ptr);
  engine.Movement_Components.emplace_back(move_component_ptr);
 
  component_factory<sprite_component> sprite_cfactory;
  
  auto spritecomponent_ptr = sprite_cfactory.get();

  
  const auto load_result = spritecomponent_ptr->Texture.loadFromFile("../../assets/tetris-block.png");
  if(load_result == false) {
    // file failed to load
    __debugbreak();
  }

  spritecomponent_ptr->Sprite.setTexture(spritecomponent_ptr->Texture);
  entity_instance->add_component(spritecomponent_ptr);
  engine.Sprite_Components.emplace_back(spritecomponent_ptr);

  component_factory<gravity_component> gravity_cfactory;
  auto gravity_component_ptr = gravity_cfactory.get();

  entity_instance->add_component(gravity_component_ptr);
  
  engine.Gravity_Components.emplace_back(gravity_component_ptr);
}

//===----------------------------------------------------------------------===//
//
// Game-specific window initialization code.
//
//===----------------------------------------------------------------------===///
void
setup_window(ec::engine &engine)
{
  const std::string window_title("Tetris-Clone by Wes & Ben");
  const sf::VideoMode window_mode(1024, 768);
  const auto window_style = sf::Style::Titlebar | sf::Style::Close |sf::Style::Resize;
 
  engine.Window.create(window_mode, window_title, window_style);
  engine.Window.setVerticalSyncEnabled(true);
}

//===----------------------------------------------------------------------===//
//
// The main game loop. When this function exits the game is over. The game loop
// iterates over the different systems in order, processing input, updating ai,
// drawing the screen, playing audio, etc...
//
//===----------------------------------------------------------------------===///
void
tet::game::game_loop(
  ec::engine &engine
  )
{
  using namespace ec;

  setup_window(engine);
  setup_test_code(engine);

  sf::Clock clock_instance;
  bool finished = false;

  while(finished == false) {

    // update the elapsed time
    engine.Elapsed_Time = clock_instance.restart().asSeconds();

    message_system::process_messages(engine);
    
    input_system::process_input(engine, finished);

    gravity_system::apply_gravitational_forces(engine);

    movement_system::move_entities(engine);

    graphics_system::update_screen(engine);
  }
}