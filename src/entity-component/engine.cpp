#include <string>
#include "engine.hpp"
#include "entity\entity_factory.hpp"
#include "component\component_factory.hpp"

//===----------------------------------------------------------------------===//
//
// The engine constructor. Initializes the Window member structure.
//
//===----------------------------------------------------------------------===//
rem::engine::engine(void)
{
  const std::string window_title("Remnant Title Text");
  const sf::VideoMode window_mode(1024, 768);
  const auto window_style = sf::Style::Titlebar | sf::Style::Close |sf::Style::Resize;
 
  Window.create(window_mode, window_title, window_style);
  Window.setVerticalSyncEnabled(true);


  // TEST CODE: Following code is for testing purposes only (referencing entiy_factory and input_component)
  entity_factory efactory;
  auto entity_instance = efactory.get();

  component_factory<input_component> input_cfactory;
  
  auto inputcomponent_ptr = input_cfactory.get();
  entity_instance->add_component(inputcomponent_ptr);
  Entities.emplace_back(entity_instance);

  Input_Component.emplace_back(inputcomponent_ptr);

  component_factory<movement_component> move_cfactory;

  auto move_component_ptr = move_cfactory.get();
  move_component_ptr->Velocity.x = 0.2f;
  move_component_ptr->Velocity.y = 0.1f;
  move_component_ptr->Acceleration.x = 0.0f;
  move_component_ptr->Acceleration.y = 0.0f;
  entity_instance->add_component(move_component_ptr);
  Movement_Components.emplace_back(move_component_ptr);
 
  component_factory<sprite_component> sprite_cfactory;
  
  auto spritecomponent_ptr = sprite_cfactory.get();

  
  const auto load_result = spritecomponent_ptr->Texture.loadFromFile("../../assets/tetris-block.png");
  if(load_result == false) {
    // file failed to load
    __debugbreak();
  }

  spritecomponent_ptr->Sprite.setTexture(spritecomponent_ptr->Texture);
  entity_instance->add_component(spritecomponent_ptr);
  Sprite_Components.emplace_back(spritecomponent_ptr);

  component_factory<gravity_component> gravity_cfactory;
  auto gravity_component_ptr = gravity_cfactory.get();

  entity_instance->add_component(gravity_component_ptr);
  
  Gravity_Components.emplace_back(gravity_component_ptr);
}