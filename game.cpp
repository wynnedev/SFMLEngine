//
// Created by 200458668 on 10/28/2021.
//

#include "game.hpp"
#include "states/splashstate.hpp"

namespace IE{
    Game::Game(int width, int height, std::string title){
        _data->window.create(sf::VideoMode( width, height ), title, sf::Style::Close | sf::Style::Titlebar);

        //set initial state
        _data->machine.PushState( StatePtr( new SplashState ( this->_data) ) );
        this->Run();
    }

    void Game::Run(){
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while( this->_data->window.isOpen()){
            this->_data->machine.ProcessStack();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if ( frameTime > .25F ){
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while( accumulator >= deltaTime){
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update( deltaTime );
                accumulator -= deltaTime;
            }

            this->_data->machine.GetActiveState()->Draw( deltaTime );
        }
    }
}