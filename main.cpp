#include "definitions.hpp"
#include "game.hpp"
#include "utils/logger.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class A{
    public: 
    int i;
};

int main()
{
    A a;
    std::cout << "result" <<  a.i;
    IE::Logger logger = IE::Logger::Instance();
    logger.SendMessage(IE::PRIORITY::INFO, "Program Initialized");
    IE::Game( SCREEN_HEIGHT, SCREEN_WIDTH, "SFML_ENGINE_RUNNING...");
    logger.SendMessage(IE::PRIORITY::INFO, "Program Terminated");


    return EXIT_SUCCESS;
}

