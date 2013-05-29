#include "observer_system.hpp"
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>
#include "iobserver.hpp"

////////////////////////////////////////////////////////////
obs::observer_system::observer_system(void) :
  _handle_counter(0)
{

}

////////////////////////////////////////////////////////////
obs::observer_handle
obs::observer_system::subscribe(obs::iobserver *const observer_ptr)
{
  const auto count = _handle_counter++;

  obs::observer_handle obshandle;
  obshandle._value = count;

  _observers.emplace(obshandle, observer_ptr);

  return obshandle;
}


////////////////////////////////////////////////////////////
void
obs::observer_system::unsubscribe(const obs::observer_handle handle)
{
  const auto iter = _observers.find(handle);

  if(iter == _observers.cend()) {
    __debugbreak();
    //BOOST_LOG_TRIVIAL(error) << "unsubscribing invalid handle" << std::endl;
  }

  const auto erase_result = _observers.erase(iter);
}


////////////////////////////////////////////////////////////
void
obs::observer_system::notify_subscribers(sf::RenderWindow &window)
{
  sf::Event event_buffer;
  while(window.pollEvent(event_buffer)) {

    if(event_buffer.type == sf::Event::KeyPressed) {
      for(const auto &iobserver_ptr : _observers) {
        iobserver_ptr.second->on_notify(event_buffer.key.code);
      }
    }
  }
  
}


////////////////////////////////////////////////////////////
bool
obs::move_handle(obs::observer_system &system, const obs::observer_handle handle, obs::iobserver *const observer_ptr)
{
  system.unsubscribe(handle);

  system.subscribe(observer_ptr);
  // TODO: implement
  return true;
}