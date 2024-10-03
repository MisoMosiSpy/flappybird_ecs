// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "Game.h"

#include "Splash.h"

Game::Game() : m_ctx{std::make_shared<Context>()} {
    m_ctx->m_window->create(sf::VideoMode(768, 1024), "Flappy Bird!");
    m_ctx->m_window->setFramerateLimit(60);

    m_ctx->m_sceneMan->addScene(std::make_unique<Splash>(m_ctx));
}

void Game::run() {
    while (m_ctx->m_window->isOpen()) {
        float dt = m_clock.restart().asSeconds();
        m_ctx->m_sceneMan->processSceneChnage();

        if (!m_ctx->m_sceneMan->isEmpty()) {
            m_ctx->m_sceneMan->getActiveScene()->handleInput();
            m_ctx->m_sceneMan->getActiveScene()->update(dt);
            m_ctx->m_sceneMan->getActiveScene()->draw();
        } else {
            m_ctx->m_window->close();
        }
    }
}
