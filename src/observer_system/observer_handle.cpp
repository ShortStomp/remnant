#include "observer_handle.hpp"

////////////////////////////////////////////////////////////
obs::observer_handle::observer_handle(void) :
  _value(obs::detached)
{

}


////////////////////////////////////////////////////////////
obs::observer_handle::observer_handle(const obs::observer_handle &other)
  : _value(other._value)
{

}


////////////////////////////////////////////////////////////
obs::observer_handle::observer_handle(obs::observer_handle &&other)
  : _value(std::move(other._value))
{

}


////////////////////////////////////////////////////////////
bool
obs::operator<(const obs::observer_handle &lhs, const obs::observer_handle &rhs)
{
  return lhs._value < rhs._value;
}