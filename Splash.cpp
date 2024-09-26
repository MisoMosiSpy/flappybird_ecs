#include "Splash.h"
#include <iostream>

void Splash::init()
{
	m_ctx->m_assetMan->addFont(TITLE_FONT, "Resources/fonts/FlappyFont.ttf");
	m_title.setFont(m_ctx->m_assetMan->getFont(TITLE_FONT));

	m_title.setString("SFML Flappy Bird");
	m_title.setFillColor(sf::Color::Black);
	m_title.setCharacterSize(80);
	m_title.setOrigin(m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2);
	m_title.setPosition(m_ctx->m_window->getSize().x / 2.0f, m_ctx->m_window->getSize().y / 2.0f);
}

void Splash::handleInput()
{
	sf::Event event;
	while (m_ctx->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_ctx->m_window->close();
	}
}

void Splash::update(float dt)
{
	static float elasped = 0;

	elasped += dt;

	if (elasped > 3.0f) {
		std::cout << "load next screen" << std::endl;
	}
}

void Splash::draw()
{

	m_ctx->m_window->clear(sf::Color{ 52,220,235,255 });
	m_ctx->m_window->draw(m_title);
	m_ctx->m_window->display();
}
 