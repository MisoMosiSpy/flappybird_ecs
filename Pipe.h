// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once
#include <memory>
#include <random>
#include <vector>

#include "Game.h"

class Pipe {
public:

    Pipe(std::shared_ptr<Context> ctx) : m_ctx{ctx} {
        std::cout << "+ Pipe" << std::endl;
        // Seed random number generator.
        srand(static_cast<unsigned int>(time(NULL)));
    }

    ~Pipe() { std::cout << "- Pipe" << std::endl; };

    void spwan(bool up = true, bool down = true);
    void draw();
    void update(float dt);

private:

    std::vector<sf::Sprite> m_pipes;
    std::shared_ptr<Context> m_ctx;
};

