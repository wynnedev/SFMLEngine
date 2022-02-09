//
// Created by 200458668 on 10/29/2021.
//

#include "splashstate.hpp"
#include "definitions.hpp"
#include "exitstate.hpp"

IE::Logger SplashStateLogger = IE::Logger::Instance();

IE::SplashState::SplashState(IE::GameDataPtr data) : _data( data ) {

}
void IE::SplashState::Init() {
    this->_data->assets.LoadTexture( "Splash_State_Background",
                                  SPLASH_SCENE_BACKGROUND_FILE_PATH);
    _background.setTexture(this->_data->assets.GetTexture("Splash_State_Background"));
}

void IE::SplashState::HandleInput() {
    sf::Event event;

    //handle close window during splash
    while( this->_data->window.pollEvent(event)){
        if(sf::Event::Closed == event.type) {
        this->_data->window.close();
      }
    }
}

void IE::SplashState::Update(float deltaTime) {

    if( this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_DISPLAY_TIME){
        _data->machine.PushState(
          StatePtr( new ExitState(this->_data)));
    }
}

void IE::SplashState::Draw(float deltaTime) {
    this->_data->window.clear(sf::Color::Black);
    this->_data->window.draw( this->_background );
    this->_data->window.display();
}
