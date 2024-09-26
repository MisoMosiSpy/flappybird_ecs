#include "AssetManager.h"

void AssetManager::addTexture(int id, std::string filename, bool isTiled)
{
	sf::Texture tempTex;

	if (tempTex.loadFromFile(filename)) {
		m_textures[id] = tempTex;
	}
}

sf::Texture& AssetManager::getTexture(int id)
{
	return m_textures[id];
}

void AssetManager::addFont(int id, std::string filename)
{
	sf::Font tempFont;

	if (tempFont.loadFromFile(filename)) {
		m_fonts[id] = tempFont;
	}
}

sf::Font& AssetManager::getFont(int id)
{
	return m_fonts[id];
}


