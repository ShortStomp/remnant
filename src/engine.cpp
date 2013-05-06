#include <string>
#include "engine.hpp"
#include "entity\entity_factory.hpp"
#include "component\input_component.hpp"
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


  // TEST CODE: Following code is for testing purposes only (referencing entiy_factor and input_component)
  entity_factory factory;
  auto instance = factory.get();
  
  auto component = new input_component;
  component->Parent_ptr = instance;
  instance->add_component(component);
  Entities.emplace_back(instance);
  this->Input_Component.emplace_back(component);
}