// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "Bird.h"

#include "Game.h"

Bird::Bird(std::shared_ptr<Context> ctx) : m_ctx(ctx) {

    for (unsigned int i = BIRD_FRAME1; i <= BIRD_FRAME4; i++) {
        m_birdFrames.push_back(m_ctx->m_assetMan->getTexture(i));
    }

    m_currentFrame = 0;
    m_birdSprite.setTexture(m_birdFrames.at(m_currentFrame));
    m_birdSprite.setOrigin(m_birdSprite.getGlobalBounds().getSize() / 2.0f);
    m_birdSprite.setPosition(m_ctx->m_window->getSize().x / 6.0f,
                             m_ctx->m_window->getSize().y / 3.0f);

    m_birdState = BirdState::IDLE;
}

void Bird::draw() {
    m_ctx->m_window->draw(m_birdSprite);
    ;
}

void Bird::update(float dt) {

    float rotation = 0;

    if (m_birdState == BirdState::FLYING) {

        m_flightTime += dt;
        if (m_flightTime > m_flightTimeout) {
            m_flightTime -= m_flightTimeout;
            m_birdState = BirdState::FALLING;
        }
    }

    if (m_birdState == BirdState::FLYING) {
        m_birdSprite.move(0, -m_ctx->m_settings->gravity * dt);
        rotation = -10;
    } else if (m_birdState == BirdState::FALLING) {
        m_birdSprite.move(0, m_ctx->m_settings->gravity * dt);
        rotation = 10;
    } else {
        rotation = 0;
    }

    m_frameDuration += dt;
    if (m_frameDuration > m_animationSpeed) {
        m_frameDuration -= m_animationSpeed;
        m_currentFrame = (m_currentFrame + 1) % m_maxFrames;
        m_birdSprite.setTexture(m_birdFrames.at(m_currentFrame));
    }

    m_birdSprite.setRotation(rotation);
}

void Bird::tap() { m_birdState = BirdState::FLYING; }

bool Bird::checkCollision(const std::vector<sf::Sprite>& spriteList) const {
    for (auto sprite : spriteList) {
        if (m_birdSprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

