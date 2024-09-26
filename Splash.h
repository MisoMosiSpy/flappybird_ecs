#pragma once
#include "Scene.h"
#include "Game.h"

class Splash :
    public Scene
{
public:
    Splash(std::shared_ptr<Context> ctx) : m_ctx { ctx }{}
    ~Splash() {}

    void init();
    void handleInput();
    void update(float dt);
    void draw();

private:
    std::shared_ptr<Context> m_ctx;
    sf::Font m_font;
    sf::Text m_title;
};

