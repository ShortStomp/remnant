#include "observer_system.hpp"
#include "iobserver.hpp"


////////////////////////////////////////////////////////////
obs::iobserver::iobserver(obs::observer_system &observer_system)
  : _observer_system(observer_system)
{
  _handle = _observer_system.subscribe(this);
}


////////////////////////////////////////////////////////////
obs::iobserver::iobserver(obs::iobserver &&other)
  : _observer_system(other._observer_system),
  _handle(std::move(other._handle))
{
  obs::move_handle(_observer_system, _handle, this);
}


////////////////////////////////////////////////////////////
obs::iobserver::~iobserver(void)
{
  _observer_system.unsubscribe(_handle);
}