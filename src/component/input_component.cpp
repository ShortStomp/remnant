#include "..\messages\message.hpp"
#include "input_component.hpp"

//===----------------------------------------------------------------------===//
//
// Verify if the message is a keypress message, if it is then process the
// keypress otherwise nothing.
//
//===----------------------------------------------------------------------===//
void 
rem::input_component::process_message(const message message) 
{
  if(message.Type == KEYPRESS_MESSAGE_TYPE) {
    ////keypress_message* keypress = static_cast<rem::keypress_message*>(message);
    //if(message->Key == sf::Keyboard::W) {
    //  // Generate Move message and send to entity
    //}
    if(message.Keypress_Message.Key == sf::Keyboard::W) {

    }
  }
}