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

  component_factory<transform_component> transform_cfactory;
  auto transform_component_ptr = transform_cfactory.get();
  transform_component_ptr->setPosition(engine.Window.getSize().x / 2.0f, engine.Window.getSize().y / 2.0f);
  entity_instance->add_component(transform_component_ptr);

  component_factory<input_component> input_cfactory;
  
  auto inputcomponent_ptr = input_cfactory.get();
  entity_instance->add_component(inputcomponent_ptr);

  component_factory<movement_component> move_cfactory;

  auto move_component_ptr = move_cfactory.get();
  //move_component_ptr->Velocity.x = 0.2f;
  //move_component_ptr->Velocity.y = 0.1f;
  move_component_ptr->Acceleration.x = 0.0f;
  move_component_ptr->Acceleration.y = 0.0f;
  entity_instance->add_component(move_component_ptr);

  component_factory<gravity_component> gravity_cfactory;
  auto gravity_component_ptr = gravity_cfactory.get();

  entity_instance->add_component(gravity_component_ptr);

  // add the entity to the  engine
  engine.Entities.emplace_back(entity_instance);
}


void
add_test_L_block_to_engine(ec::engine &engine, ec::entity *parent_entity_ptr, const sf::Vector2f &offset)
{
  using namespace ec;

  const entity_factory ef;
  const auto e0 = ef.get();
  e0->Parent = parent_entity_ptr;

  const component_factory<sprite_component> sprite_cfactory;
  
  auto spritecomponent_ptr = sprite_cfactory.get();
  const auto load_result = spritecomponent_ptr->Texture.loadFromFile("../../assets/tetris-block.png");
  if(load_result == false) {
    // file failed to load
    __debugbreak();
  }

  spritecomponent_ptr->Sprite.setTexture(spritecomponent_ptr->Texture);
  e0->add_component(spritecomponent_ptr);
  
  // the two entities are sharing the transform component
  //const auto shared_transform_component_ptr = entity_helpers::get_transform_component(parent_entity_ptr);
  const component_factory<transform_component> transform_cfactory;
  const auto shared_transform_component_ptr = transform_cfactory.get();
  shared_transform_component_ptr->move(offset);
  e0->add_component(shared_transform_component_ptr);
  
  engine.Entities.emplace_back(e0);
}

void
add_border_to_engine(ec::engine &engine)
{
  using namespace ec;

  const entity_factory ef;
  const auto e0 = ef.get();

  const component_factory<sprite_component> sprite_cfactory;

  auto spritecomponent_ptr = sprite_cfactory.get();

  const auto load_result = spritecomponent_ptr->Texture.loadFromFile("../../assets/border.png");
  if(load_result == false) {
    __debugbreak();
  }
  
  spritecomponent_ptr->Sprite.setTexture(spritecomponent_ptr->Texture);
  spritecomponent_ptr->Sprite.setOrigin(-1 * ((engine.Window.getSize().x - 400.0f) / 2), -1 * ((engine.Window.getSize().y - 600.0f) / 2));
  e0->add_component(spritecomponent_ptr);
  
   // the two entities are sharing the transform component
  //const auto shared_transform_component_ptr = entity_helpers::get_transform_component(parent_entity_ptr);

  component_factory<transform_component> transform_cfactory;
  auto transform_component_ptr = transform_cfactory.get();
  
  e0->add_component(transform_component_ptr);

  engine.Entities.emplace_back(e0);
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
  
  const auto parent_entity = engine.Entities.front();
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(-15.0f, -15.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(-15.0f, 0.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(-15.0f, 15.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(0.0f, 15.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(15.0f, 15.0f));

  add_border_to_engine(engine);

  sf::Clock clock_instance;
  bool finished = false;

  while(finished == false) {

    // update the elapsed time
    engine.Elapsed_Time = clock_instance.restart().asSeconds();

    message_system::process_messages(engine);
    
    input_system::process_input(engine, finished);

    //gravity_system::apply_gravitational_forces(engine);

    movement_system::move_entities(engine);

    graphics_system::update_screen(engine);
  }
}