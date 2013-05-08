#include <string>
#include "engine.hpp"
#include "entity\entity_factory.hpp"
#include "component\input_component.hpp"
#include "component\sprite_component.hpp"

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
  entity_factory factory;
  auto instance = factory.get();
  
  auto inputcomponent = new input_component;
  instance->add_component(inputcomponent);
  Entities.emplace_back(instance);

  Input_Component.emplace_back(inputcomponent);
  
  auto spritecomponent = new sprite_component;
  const auto load_result = spritecomponent->Texture.loadFromFile("../assets/grassd.gif");
  if(load_result == false) {
    // file failed to load
    __debugbreak();
  }

  spritecomponent->Sprite.setTexture(spritecomponent->Texture);
  instance->add_component(spritecomponent);
  Sprite_Components.emplace_back(spritecomponent);
}