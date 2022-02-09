//
// Created by 200458668 on 10/28/2021.
//

#include "assetmanager.hpp"
#include <iostream>

namespace IE{
    void AssetManager::LoadTexture( std::string name, std::string fileName ){
        sf::Texture texture;

        ///ADD check for existing KEY name
        if(texture.loadFromFile( fileName) ){
            this->_textures[name] = texture;
        }

        else{
            //TODO Handle Texture Load Error
            std::cerr << "Texture File Load Error";
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string name) {
        return this->_textures[name];
    }

    void AssetManager::LoadFont( std::string name, std::string fileName ){
        sf::Font font;

        ///ADD check for existing KEY name
        if(font.loadFromFile( fileName) ){
            this->_fonts[name] = font;
        }

        else{
            ///TODO Handle File Load Error
            std::cerr << "Font File Load Error";
        }
    }

    sf::Font &AssetManager::GetFont(std::string name) {
        return this->_fonts[name];
    }
}