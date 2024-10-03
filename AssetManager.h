// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class AssetManager {
public:

    AssetManager() {}

    ~AssetManager() {}

    void addTexture(int id, std::string filename, bool isTiled = false);
    sf::Texture& getTexture(int id);

    void addFont(int id, std::string filename);
    sf::Font& getFont(int id);

private:

    std::map<int, sf::Texture> m_textures;
    std::map<int, sf::Font> m_fonts;
};

