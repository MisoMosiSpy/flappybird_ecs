// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"

class Bird {
public:

    Bird(std::shared_ptr<Context> ctx);

    ~Bird() {}

    void draw();
    void update(float dt);

private:

    std::shared_ptr<Context> m_ctx;
    std::vector<sf::Texture> m_birdFrames;
    sf::Sprite m_birdSprite;

    unsigned int m_currentFrame{0};
    float m_frameDuration{0};

    const unsigned int m_maxFrames{4};
    const float m_animationSpeed{0.1f};
};

