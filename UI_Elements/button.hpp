//
// Created by 200458668 on 2/8/2022.
//

#ifndef SFML_ENGINE_BUTTON_HPP
#define SFML_ENGINE_BUTTON_HPP
#include <SFML/Graphics.hpp>

namespace GUI {

enum class BUTTON_STYLE{
  none = 0;
  save = 1;
  cancel = 2;
  clean = 3;
  play = 4;
  quit = 5;
};

enum class BUTTON_STATUS{
  normal;
  hovered;
  clicked;
};

enum class BUTTON_VISIBILITY{
  visible;
  invisible;
};

enum class BUTTON_STATE{
  enabled;
  disabled;
};

class Button : public sf::Drawable {
public:
  void SetButtonStatus();
  void SetButtonStyle();
  void SetButtonVisibility();
  void SetButtonState();
private:
  BUTTON_STATUS _buttonState;
  BUTTON_STYLE _buttonStyle;
  BUTTON_VISIBILIY _buttonVisibility;
  BUTTON_STATE _buttonState;
};
};

#endif // SFML_ENGINE_BUTTON_HPP
