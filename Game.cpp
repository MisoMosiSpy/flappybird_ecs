#include "Game.h"

Game::Game()
{
	ctx = std::make_shared<Context>();
	ctx->m_assetMan = std::make_unique<AssetManager>();
	ctx->m_inputMan = std::make_unique<InputManager>();
	ctx->m_sceneMan = std::make_unique<SceneManager>();
	ctx->m_window = std::make_unique<sf::RenderWindow>();

	ctx->m_window->create(sf::VideoMode(600, 300), "ECS Rocks");
	ctx->m_window->setFramerateLimit(60);

}

void Game::run()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (ctx->m_window->isOpen())
	{
		sf::Event event;
		while (ctx->m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				ctx->m_window->close();
		}

		ctx->m_window->clear();
		ctx->m_window->draw(shape);
		ctx->m_window->display();
	}

}
