#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "SceneManager.h"
#include "InputManager.h"

enum Fonts {
	TITLE_FONT = 0,
};

enum Graphics {
	BACKGROUND = 0,
	PLAY_BUTTON,
};

struct Context {
	std::unique_ptr<AssetManager> m_assetMan;
	std::unique_ptr<SceneManager> m_sceneMan;
	std::unique_ptr<InputManager> m_inputMan;
	std::unique_ptr<sf::RenderWindow> m_window;


	Context() {
		m_assetMan = std::make_unique<AssetManager>();
		m_inputMan = std::make_unique<InputManager>();
		m_sceneMan = std::make_unique<SceneManager>();
		m_window = std::make_unique<sf::RenderWindow>();
	}
};

class Game
{
public:
	Game();
	~Game() {};

	void run();

private:
	std::shared_ptr<Context> m_ctx;
	sf::Clock m_clock;
};

