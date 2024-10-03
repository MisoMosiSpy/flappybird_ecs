// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once
#include "Game.h"
#include "Scene.h"

class Splash : public Scene {
public:

    Splash(std::shared_ptr<Context> ctx) : m_ctx{ctx} {}

    ~Splash() {}

    void init();
    void handleInput();
    void update(float dt);
    void draw();

private:

    std::shared_ptr<Context> m_ctx;
    sf::Font m_font;
    sf::Text m_title;
    sf::Sprite m_playButton;
    sf::Sprite m_background;
};

