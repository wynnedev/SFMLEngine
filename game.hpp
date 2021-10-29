//
// Created by 200458668 on 10/28/2021.
//

#ifndef SFMLTEST_GAME_HPP
#define SFMLTEST_GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace IE {

    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataPtr;
    class Game {
    public:
        Game( int width, int height, std::string name);
        ~Game() = default;

    private:
        const float deltaTime = 1.0f / 60.0f;
        sf::Clock _clock;
        GameDataPtr _data = std::make_shared<GameData>();
        void Run();
    };
}


#endif//SFMLTEST_GAME_HPP
