//
// Created by 200458668 on 10/28/2021.
//

#include "inputmanager.hpp"

namespace IE{
    ///TODO refactor only call if the mouse button is pressed pass in positions of mouse pointer
    ///TODO refactor to use GetMousePosition Function internally
    bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow ){
        if( sf::Mouse::isButtonPressed( button )){
            sf::IntRect tempRect ( object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height );

            //check for collision with object
            return tempRect.contains( sf::Mouse::getPosition());
        }

        return false;
    }

    sf::Vector2i GetMousePosition( sf::RenderWindow & window ){
        return sf::Mouse::getPosition( window );
    }
}
