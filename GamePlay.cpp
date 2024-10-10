// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "GamePlay.h"

#include "Land.h"
#include "Pipe.h"

void GamePlay::init() {

    // Load all textures needed for the Gameplay Scene here
    //
    m_ctx->m_assetMan->addTexture(GROUND, "Resources/res/land.png");

    // Pipes
    m_ctx->m_assetMan->addTexture(PIPE_UP, "Resources/res/PipeUp.png");
    m_ctx->m_assetMan->addTexture(PIPE_DOWN, "Resources/res/PipeDown.png");

    // Bird
    m_ctx->m_assetMan->addTexture(BIRD_FRAME1, "Resources/res/bird-01.png");
    m_ctx->m_assetMan->addTexture(BIRD_FRAME2, "Resources/res/bird-02.png");
    m_ctx->m_assetMan->addTexture(BIRD_FRAME3, "Resources/res/bird-03.png");
    m_ctx->m_assetMan->addTexture(BIRD_FRAME4, "Resources/res/bird-04.png");

    // The texture for the background is already loaded in the Splash screen
    // However, we add it here again as our asset manager can detect this
    // and it makes this state independent of other state
    m_ctx->m_assetMan->addTexture(BACKGROUND, "Resources/res/sky.png");
    m_background.setTexture(m_ctx->m_assetMan->getTexture(BACKGROUND));
    m_background.move(0, -200);  // We want to see the building in the center

    m_land = std::make_unique<Land>(m_ctx);
    m_pipe = std::make_unique<Pipe>(m_ctx);
    m_bird = std::make_unique<Bird>(m_ctx);

    m_state = GameState::GAME_IDLE;
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

    m_bird->handleInput();
}

void GamePlay::update(float dt) {
    if (m_state != GameState::GAME_OVER) {
        m_land->update(dt);
        m_pipe->update(dt);
        m_bird->update(dt);

        if (m_bird->checkCollision(m_land->getGroundList())) {
            std::cout << "Collieded with ground" << std::endl;
            m_state = GameState::GAME_OVER;
        }

        if (m_bird->checkCollision(m_pipe->getPipesList())) {
            std::cout << "Collieded with Pipe" << std::endl;
            m_state = GameState::GAME_OVER;
        }
    }
}

void GamePlay::draw() {
    m_ctx->m_window->clear();
    m_ctx->m_window->draw(m_background);
    m_pipe->draw();
    m_land->draw();
    m_bird->draw();
    m_ctx->m_window->display();
}