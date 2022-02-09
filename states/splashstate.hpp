//
// Created by 200458668 on 10/29/2021.
//

#ifndef SFMLTEST_SPLASHSTATE_HPP
#define SFMLTEST_SPLASHSTATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

namespace IE {
    class SplashState : public State {
    public:
        explicit SplashState( GameDataPtr data );
        void Init() override;
        void HandleInput( ) override;
        void Update( float deltaTime ) override;
        void Draw( float deltaTime ) override;

    private:
        GameDataPtr _data;
        sf::Clock _clock;
        sf::Sprite _background;
    };
}


#endif//SFMLTEST_SPLASHSTATE_HPP
