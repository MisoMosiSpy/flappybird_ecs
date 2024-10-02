#include "AssetManager.h"

void AssetManager::addTexture(int id, std::string filename, bool isTiled)
{
	sf::Texture tempTex;

	if (m_textures.find(id) == m_textures.end()) {
		if (tempTex.loadFromFile(filename)) {
			m_textures[id] = tempTex;
		}
	}
}

sf::Texture& AssetManager::getTexture(int id)
{
	return m_textures.at(id);
}

void AssetManager::addFont(int id, std::string filename)
{
	sf::Font tempFont;

	if (m_fonts.find(id) == m_fonts.end()) {
		if (tempFont.loadFromFile(filename)) {
			m_fonts[id] = tempFont;
		}
	}
}

sf::Font& AssetManager::getFont(int id)
{
	return m_fonts.at(id);
}


