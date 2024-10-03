// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "GamePlay.h"

#include "Land.h"
#include "Pipe.h"

void GamePlay::init() {

    // Load all textures needed for the Gameplay Scene here
    //
    m_ctx->m_assetMan->addTexture(GROUND, "Resources/res/land.png");
    m_ctx->m_assetMan->addTexture(PIPE_UP, "Resources/res/PipeUp.png");
    m_ctx->m_assetMan->addTexture(PIPE_DOWN, "Resources/res/PipeDown.png");

    // The texture for the background is already loaded in the Splash screen
    // However, we add it here again as our asset manager can detect this
    // and it makes this state independent of other state
    m_ctx->m_assetMan->addTexture(BACKGROUND, "Resources/res/sky.png");
    m_background.setTexture(m_ctx->m_assetMan->getTexture(BACKGROUND));

    m_land = std::make_unique<Land>(m_ctx);
    m_pipe = std::make_unique<Pipe>(m_ctx);
}

void GamePlay::handleInput() {
    sf::Event event;
    while (m_ctx->m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_ctx->m_sceneMan->removeCurrentScene();
        }

        // TODO: Replace this with timer
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                m_pipe->spwan();
            }
        }
    }
}

void GamePlay::update(float dt) {
    m_land->update(dt);
    m_pipe->update(dt);
}

void GamePlay::draw() {
    m_ctx->m_window->clear();
    m_ctx->m_window->draw(m_background);
    m_pipe->draw();
    m_land->draw();
    m_ctx->m_window->display();
}