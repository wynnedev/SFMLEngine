//
// Created by 200458668 on 2/4/2022.
//

#include "exitstate.hpp"
#include "definitions.hpp"
#include "utils/logger.hpp"

IE::Logger ExitStatelogger = IE::Logger::Instance();

IE::ExitState::ExitState(IE::GameDataPtr data) : _data( data ) {

}

void IE::ExitState::Init(){
  this->_data->assets.LoadTexture("Exit_State_Background",
                                  EXIT_SCREEN_FILE_PATH);

  _background.setTexture(this->_data->assets.GetTexture("Exit_State_Background"));
}

void IE::ExitState::HandleInput(){
  sf::Event event;

  //handle close window during splash
  while( this->_data->window.pollEvent(event)){
    if(sf::Event::Closed == event.type) {
      this->_data->window.close();
    }
  }
}

void IE::ExitState::Update(float deltaTime) {
  if (this->_clock.getElapsedTime().asSeconds() > EXIT_STATE_DISPLAY_TIME) {
    _data->machine.PopState();
    this->_data->window.close();
  }
}

void IE::ExitState::Draw(float deltaTime){
  this->_data->window.clear(sf::Color::Black);
  this->_data->window.draw( this->_background );
  this->_data->window.display();
}