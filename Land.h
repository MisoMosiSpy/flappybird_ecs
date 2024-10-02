#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>

class Land
{
public: 
	Land(std::shared_ptr<Context> ctx);
	~Land() {};

	void draw();
	void update(float dt);

private:
	std::shared_ptr<Context> m_ctx;
	std::vector<sf::Sprite> m_grounds;
	const int m_landSpriteCount = 2;
};

