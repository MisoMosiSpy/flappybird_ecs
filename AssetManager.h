#pragma once
#include <map>
#include <SFML/Graphics.hpp>

#include <iostream>

class AssetManager
{
public:
	AssetManager() { std::cout << "+ assman" << std::endl; };
	~AssetManager() { std::cout << "- assman" << std::endl; }

	void addTexture(int id, std::string filename, bool isTiled = false);
	sf::Texture& getTexture(int id);

	void addFont(int id, std::string filename);
	sf::Font& getFont(int id);

private:
	std::map<int, sf::Texture> m_textures;
	std::map<int, sf::Font> m_fonts;
};

