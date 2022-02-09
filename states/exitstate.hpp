//
// Created by 200458668 on 2/4/2022.
//

#ifndef SFML_ENGINE_EXITSTATE_HPP
#define SFML_ENGINE_EXITSTATE_HPP
#include "state.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>

namespace IE {
  class ExitState : public State {
  public:
    explicit ExitState(GameDataPtr data);
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

#endif // SFML_ENGINE_EXITSTATE_HPP
