// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "Pipe.h"

void Pipe::spwan(bool up, bool down) {

    float offset = static_cast<float>(rand() % m_ctx->m_settings->pipeVariation);

    if (up) {
        sf::Sprite pipeUp(m_ctx->m_assetMan->getTexture(PIPE_UP));
        pipeUp.setPosition(static_cast<float>(m_ctx->m_window->getSize().x),
                           m_ctx->m_window->getSize().y - pipeUp.getGlobalBounds().height - offset);
        m_pipes.push_back(pipeUp);
    }

    if (down) {
        sf::Sprite pipeDown(m_ctx->m_assetMan->getTexture(PIPE_DOWN));
        pipeDown.setPosition(static_cast<float>(m_ctx->m_window->getSize().x), -offset);
        m_pipes.push_back(pipeDown);
    }
}

void Pipe::draw() {
    for (auto& pipe : m_pipes) {
        m_ctx->m_window->draw(pipe);
    }
}

void Pipe::update(float dt) {
    for (auto& pipe : m_pipes) {
        pipe.move(-m_ctx->m_settings->gameSpeed * dt, 0);
    }

    // Remove invisible sprites (Using erase-remove-idom)
    auto it = std::remove_if(m_pipes.begin(), m_pipes.end(), [](auto& p) {
        return p.getPosition().x + p.getGlobalBounds().width < 0;
    });

    m_pipes.erase(it, m_pipes.end());
}
