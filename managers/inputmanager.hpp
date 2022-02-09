//
// Created by 200458668 on 10/28/2021.
//

#ifndef SFMLTEST_INPUTMANAGER_HPP
#define SFMLTEST_INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace IE {
    class InputManager {
    public:
        InputManager() = default;
        ~InputManager() = default;

        bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow );
        sf::Vector2i GetMousePosition( sf::RenderWindow & window );
    };
}


#endif//SFMLTEST_INPUTMANAGER_HPP
