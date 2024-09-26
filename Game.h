#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "SceneManager.h"
#include "InputManager.h"

struct Context {
	std::unique_ptr<AssetManager> m_assetMan;
	std::unique_ptr<SceneManager> m_sceneMan;
	std::unique_ptr<InputManager> m_inputMan;
	std::unique_ptr<sf::RenderWindow> m_window;
};

class Game
{
public:
	Game();
	~Game() {};

	void run();

private:
	std::shared_ptr<Context> ctx;
};

