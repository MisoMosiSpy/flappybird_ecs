// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "Splash.h"

#include <iostream>

#include "GamePlay.h"

void Splash::init() {
    m_ctx->m_assetMan->addFont(TITLE_FONT, "Resources/fonts/FlappyFont.ttf");
    m_title.setFont(m_ctx->m_assetMan->getFont(TITLE_FONT));

    m_title.setString("SFML Flappy Bird");
    m_title.setFillColor(sf::Color::Black);
    m_title.setCharacterSize(80);
    m_title.setOrigin(m_title.getGlobalBounds().getSize() / 2.0f);
    m_title.setPosition(m_ctx->m_window->getSize().x / 2.0f, m_ctx->m_window->getSize().y / 4.0f);

    m_ctx->m_assetMan->addTexture(BACKGROUND, "Resources/res/sky.png");
    m_background.setTexture(m_ctx->m_assetMan->getTexture(BACKGROUND));

    m_ctx->m_assetMan->addTexture(PLAY_BUTTON, "Resources/res/PlayButton.png");
    m_playButton.setTexture(m_ctx->m_assetMan->getTexture(PLAY_BUTTON));
    m_playButton.setOrigin(m_playButton.getGlobalBounds().getSize() / 2.0f);
    m_playButton.setPosition(m_ctx->m_window->getSize().x / 2.0f,
                             m_ctx->m_window->getSize().y / 2.0f);
}

void Splash::handleInput() {
    sf::Event event;
    while (m_ctx->m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) m_ctx->m_sceneMan->removeCurrentScene();
    }

    if (m_ctx->m_inputMan->isSpriteClicked(m_playButton, sf::Mouse::Left, *m_ctx->m_window.get())) {
        std::cout << "Load next state..." << std::endl;
        m_ctx->m_sceneMan->addScene(std::make_unique<GamePlay>(m_ctx));
    }
}

void Splash::update(float dt) {}

void Splash::draw() {
    m_ctx->m_window->clear(sf::Color{52, 220, 235, 255});
    m_ctx->m_window->draw(m_background);
    m_ctx->m_window->draw(m_title);
    m_ctx->m_window->draw(m_playButton);
    m_ctx->m_window->display();
}
