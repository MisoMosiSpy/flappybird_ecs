// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "Land.h"

Land::Land(std::shared_ptr<Context> ctx) : m_ctx{ctx} {
    // We use two ground sprites, stacket horizontially next to each other
    // When the leftmost sprite is moved out of window it will be moved back
    // at the end of second sprite to provide endless scroll.
    for (int i = 0; i < m_landSpriteCount; i++) {
        sf::Sprite temp;
        temp.setTexture(m_ctx->m_assetMan->getTexture(GROUND));
        // poistion it at the bottom of the window
        temp.setPosition(i * temp.getGlobalBounds().width,
                         m_ctx->m_window->getSize().y - temp.getGlobalBounds().height);

        m_grounds.push_back(temp);
    }
}

void Land::draw() {
    for (auto& s : m_grounds) {
        m_ctx->m_window->draw(s);
    }
}

void Land::update(float dt) {
    for (int i = 0; i < m_landSpriteCount; i++) {
        sf::Sprite& s = m_grounds[i];
        s.move(-m_ctx->m_settings->gameSpeed * dt, 0);
    }

    // TODO: How can we do this programatically without assuming that, there will
    //       be only two sprites used for land scroll effect.
    if (m_grounds[0].getPosition().x + m_grounds[0].getGlobalBounds().width < 0) {
        m_grounds[0].setPosition(
            m_grounds[1].getPosition().x + m_grounds[1].getGlobalBounds().width,
            m_grounds[0].getPosition().y);
    } else if (m_grounds[1].getPosition().x + m_grounds[1].getGlobalBounds().width < 0) {
        m_grounds[1].setPosition(
            m_grounds[0].getPosition().x + m_grounds[0].getGlobalBounds().width,
            m_grounds[1].getPosition().y);
    }
}
