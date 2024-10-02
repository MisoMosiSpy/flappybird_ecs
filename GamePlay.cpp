#include "GamePlay.h"

void GamePlay::init()
{
	// The texture for the background is already loaded in the Splash screen
	// However, we add it here again as our asset manager can detect this 
	// and it makes this state independent of other state
	m_ctx->m_assetMan->addTexture(BACKGROUND, "Resources/res/sky.png");
	m_background.setTexture(m_ctx->m_assetMan->getTexture(BACKGROUND));

	// Setup sprite for the land texture
	m_ctx->m_assetMan->addTexture(GROUND, "Resources/res/land.png");

	m_land = std::make_unique<Land>(m_ctx);
}

void GamePlay::handleInput()
{
	sf::Event event;
	while (m_ctx->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_ctx->m_sceneMan->removeCurrentScene();
	}
}

void GamePlay::update(float dt)
{
	m_land->update(dt);
}

void GamePlay::draw()
{
	m_ctx->m_window->clear();
	m_ctx->m_window->draw(m_background);
	m_land->draw();
	m_ctx->m_window->display();
}