//
// Created by 200458668 on 2/5/2022.
//

#ifndef SFML_ENGINE_MAINMENUSTATE_HPP
#define SFML_ENGINE_MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

namespace IE{
  class MainMenuState : public State {
  public:
    explicit MainMenuState( GameDataPtr data );
    void Init() override;
    void HandleInput( ) override;
    void Update( float deltaTime ) override;
    void Draw( float deltaTime ) override;

  private:
    void DrawMainMenu();
    GameDataPtr _data;
    sf::Clock _clock;
    sf::Sprite _background;

  };
}


#endif // SFML_ENGINE_MAINMENUSTATE_HPP
