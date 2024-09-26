#pragma once

#include <memory>
#include <stack>

#include "Scene.h"

class SceneManager
{
public:
	SceneManager() {}
	~SceneManager() {}

	void addScene(std::unique_ptr<Scene> newScene, bool isReplacing = true);
	void removeScene();
	void processSceneChnage();
	std::unique_ptr<Scene>& getActiveScene();

private:
	std::stack<std::unique_ptr<Scene>> m_scenes;
	std::unique_ptr<Scene> m_sceneToAdd;
	bool m_isAdding{};
	bool m_isRemoving{};
	bool m_isReplacing{};
};

