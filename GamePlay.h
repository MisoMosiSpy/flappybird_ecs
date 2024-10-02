#pragma once
#include "Scene.h"
#include "Game.h"
#include "land.h"

class GamePlay : public Scene
{
public:
	GamePlay(std::shared_ptr<Context> ctx) :  m_ctx{ctx} {}
	~GamePlay() {};


	void init();
	void handleInput();
	void update(float dt);
	void draw();

	void pause() {};
	void resume() {};
	
private:
	std::shared_ptr<Context> m_ctx;
	sf::Sprite m_background;
	std::unique_ptr<Land> m_land;
};

