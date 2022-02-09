//
// Created by 200458668 on 10/28/2021.
//

#ifndef SFMLTEST_ASSETMANAGER_HPP
#define SFMLTEST_ASSETMANAGER_HPP
#include <map>
#include <SFML/Graphics.hpp>

///TODO look in GIResource Class to see if you can load multiple resources using the same function

namespace IE {
    class AssetManager {
    public:
        AssetManager() {};
        ~AssetManager() {};

        void LoadTexture ( std::string assetName, std::string fileName );
        sf::Texture &GetTexture ( std::string name );

        void LoadFont ( std::string assetName, std::string fileName );
        sf::Font &GetFont ( std::string name );

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}


#endif//SFMLTEST_ASSETMANAGER_HPP
