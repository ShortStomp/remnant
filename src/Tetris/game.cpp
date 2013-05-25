#include <SFML\Window\Event.hpp>
#include <boost\log\trivial.hpp>
#include "..\entity-component\\engine.hpp"
#include "..\entity-component\system\message_system.hpp"
#include "..\entity-component\system\input_system.hpp"
#include "..\entity-component\system\movement_system.hpp"
#include "..\entity-component\system\graphics_system.hpp"
#include "..\entity-component\system\gravity_system.hpp"
#include "..\entity-component\\system\collision_system.hpp"
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
  transform_component_ptr->setPosition((engine.Window.getSize().x - 400) / 2.0f, (engine.Window.getSize().y - 600) / 2.0f);
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
set_game_border_parent(ec::engine &engine)
{
  using namespace ec;

  entity_factory efactory;
  auto entity_instance = efactory.get();
  
  component_factory<transform_component> transform_cfactory;
  auto transform_component_ptr = transform_cfactory.get();
  
  transform_component_ptr->setPosition(engine.Window.getSize().x / 4.0f, engine.Window.getSize().y / 4.0f);
  BOOST_LOG_TRIVIAL(warning) << "PARENT X: " + std::to_string(transform_component_ptr->getPosition().x) + "Y:" + std::to_string(transform_component_ptr->getPosition().y) << std::endl;
  entity_instance->add_component(transform_component_ptr);

  component_factory<input_component> input_cfactory;
  
  auto inputcomponent_ptr = input_cfactory.get();
  entity_instance->add_component(inputcomponent_ptr);

  engine.Entities.emplace_back(entity_instance);   
}
void
  add_top_bottom_wall_to_border(ec::engine &engine, ec::entity *parent_entity_ptr, const sf::Vector2f &offset)
{
   using namespace ec;

  const entity_factory ef;
  const auto e0 = ef.get();
  
  e0->Parent = parent_entity_ptr;

  const component_factory<sprite_component> sprite_cfactory;
  
  auto spritecomponent_ptr = sprite_cfactory.get();
  const auto load_result = spritecomponent_ptr->Texture.loadFromFile("../../assets/bottom_top_border.png");
  if(load_result == false) {
    // file failed to load
    __debugbreak();
  }

  spritecomponent_ptr->Sprite.setTexture(spritecomponent_ptr->Texture);
  e0->add_component(spritecomponent_ptr); 
  
  const component_factory<transform_component> transform_cfactory;
  const auto shared_transform_component_ptr = transform_cfactory.get();
  shared_transform_component_ptr->move(offset);
  e0->add_component(shared_transform_component_ptr);
  
  const auto parent_transform_component_ptr = ec::entity_helpers::get_transform_component(parent_entity_ptr);
  const auto transform_component_ptr = transform_cfactory.get();
     
  transform_component_ptr->setPosition(parent_transform_component_ptr->getPosition().x + offset.x, parent_transform_component_ptr->getPosition().y + offset.y);
  
  BOOST_LOG_TRIVIAL(warning) << "TOP BOTTOM X: " + std::to_string(transform_component_ptr->getPosition().x) + "Y:" + std::to_string(transform_component_ptr->getPosition().y) << std::endl;
  e0->add_component(transform_component_ptr);

  if(e0->Parent != nullptr) {
    e0->Parent->Child_List.push_back(e0);
  }

  const component_factory<collision_component> collision_cfactory;
  auto collisioncomponent_ptr = collision_cfactory.get();

  e0->add_component(collisioncomponent_ptr);
  
  engine.Entities.emplace_back(e0);
}
void 
  add_left_right_wall_to_border(ec::engine &engine, ec::entity *parent_entity_ptr, const sf::Vector2f &offset)
{
     using namespace ec;

  const entity_factory ef;
  const auto e0 = ef.get();
  
  e0->Parent = parent_entity_ptr;

  const component_factory<sprite_component> sprite_cfactory;
  
  auto spritecomponent_ptr = sprite_cfactory.get();
  const auto load_result = spritecomponent_ptr->Texture.loadFromFile("../../assets/left_right_border.png");
  if(load_result == false) {
    // file failed to load
    __debugbreak();
  }

  spritecomponent_ptr->Sprite.setTexture(spritecomponent_ptr->Texture);
  e0->add_component(spritecomponent_ptr); 
  
  const component_factory<transform_component> transform_cfactory;
  const auto shared_transform_component_ptr = transform_cfactory.get();
  shared_transform_component_ptr->move(offset);
  e0->add_component(shared_transform_component_ptr);
  
  const auto parent_transform_component_ptr = ec::entity_helpers::get_transform_component(parent_entity_ptr);
  const auto transform_component_ptr = transform_cfactory.get();
     
  transform_component_ptr->setPosition(parent_transform_component_ptr->getPosition().x + offset.x, parent_transform_component_ptr->getPosition().y + offset.y);
  
  BOOST_LOG_TRIVIAL(warning) << "LEFT RIGTH X: " + std::to_string(transform_component_ptr->getPosition().x) + "Y:" + std::to_string(transform_component_ptr->getPosition().y) << std::endl;
  e0->add_component(transform_component_ptr);

  if(e0->Parent != nullptr) {
    e0->Parent->Child_List.push_back(e0);
  }

  const component_factory<collision_component> collision_cfactory;
  auto collisioncomponent_ptr = collision_cfactory.get();

  e0->add_component(collisioncomponent_ptr);
  
  engine.Entities.emplace_back(e0);
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
  
  const component_factory<transform_component> transform_cfactory;
  const auto shared_transform_component_ptr = transform_cfactory.get();
  shared_transform_component_ptr->move(offset);
  e0->add_component(shared_transform_component_ptr);

  const component_factory<movement_component> movement_cfactory;
  const auto movement_component_ptr = movement_cfactory.get();
  movement_component_ptr->Velocity.y = 0.1f;
  e0->add_component(movement_component_ptr);

  
  const auto parent_transform_component_ptr = ec::entity_helpers::get_transform_component(parent_entity_ptr);
  const auto transform_component_ptr = transform_cfactory.get();
     
  //transform_component_ptr->move(offset);
  transform_component_ptr->setPosition(parent_transform_component_ptr->getPosition().x + offset.x, parent_transform_component_ptr->getPosition().y + offset.y);
  
  BOOST_LOG_TRIVIAL(warning) << "X: " + std::to_string(transform_component_ptr->getPosition().x) + "Y:" + std::to_string(transform_component_ptr->getPosition().y) << std::endl;
  e0->add_component(transform_component_ptr);

  if(e0->Parent != nullptr) {
    e0->Parent->Child_List.push_back(e0);
  }

  const component_factory<collision_component> collision_cfactory;
  auto collisioncomponent_ptr = collision_cfactory.get();

  e0->add_component(collisioncomponent_ptr);
  
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
  
  const component_factory<collision_component> collision_cfactory;
  auto collisioncomponent_ptr = collision_cfactory.get();
  parent_entity->add_component(collisioncomponent_ptr);
  parent_entity->Child_List = std::vector<entity*>();
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(-15.0f, -15.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(-15.0f, 0.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(-15.0f, 15.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(0.0f, 15.0f));
  add_test_L_block_to_engine(engine, parent_entity, sf::Vector2f(15.0f, 15.0f));
  
  set_game_border_parent(engine);
  
  const auto parent_entity2 = engine.Entities.back();
  
  const component_factory<collision_component> collision_cfactory2;
  auto collisioncomponent_ptr2 = collision_cfactory2.get();
  parent_entity2->add_component(collisioncomponent_ptr2);
  parent_entity2->Child_List = std::vector<entity*>();
  add_top_bottom_wall_to_border(engine, parent_entity2, sf::Vector2f(-200, -300));
  add_top_bottom_wall_to_border(engine, parent_entity2, sf::Vector2f(-200, 300));
  add_left_right_wall_to_border(engine, parent_entity2, sf::Vector2f(-200, -300));
  add_left_right_wall_to_border(engine, parent_entity2, sf::Vector2f(200, -300));
  
  sf::Clock clock_instance;
  bool finished = false;

  while(finished == false) {

    // update the elapsed time
    engine.Elapsed_Time = clock_instance.restart().asSeconds();

    message_system::process_messages(engine);
    
    input_system::process_input(engine, finished);

    //gravity_system::apply_gravitational_forces(engine);

    collision_system::update_bounding_boxes(engine);

    movement_system::move_entities(engine);

    graphics_system::update_screen(engine);
  }
}