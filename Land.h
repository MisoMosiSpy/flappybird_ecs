// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"

class Land {
public:

    Land(std::shared_ptr<Context> ctx);
    ~Land(){};

    void draw();
    void update(float dt);

private:

    std::shared_ptr<Context> m_ctx;
    std::vector<sf::Sprite> m_grounds;
    const int m_landSpriteCount = 2;
};

