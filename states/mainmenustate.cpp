//
// Created by 200458668 on 2/5/2022.
//

#include "mainmenustate.hpp"
#include "exitstate.hpp"

IE::MainMenuState::MainMenuState(GameDataPtr data) : _data(data){

}

void IE::MainMenuState::Init(){
  this->_data->assets.LoadTexture("")
}