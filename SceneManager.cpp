#include "SceneManager.h"

void SceneManager::addScene(std::unique_ptr<Scene> newScene, bool isReplacing)
{
	m_sceneToAdd = std::move(newScene);

	m_isReplacing = isReplacing;
	m_isAdding = true;
}

void SceneManager::removeScene()
{
	m_isRemoving = true;
}

void SceneManager::processSceneChnage()
{
	if (m_isRemoving && !m_scenes.empty())
	{
		m_scenes.pop();

		if (!m_scenes.empty()) {
			m_scenes.top()->resume();
		}

		m_isRemoving = false;
	}

	if (m_isAdding) {
		if (m_isReplacing && !m_scenes.empty()) {
			m_scenes.pop();
		}

		if (!m_scenes.empty()) {
			m_scenes.top()->pause();
		}

		m_scenes.push(std::move(m_sceneToAdd));
		m_scenes.top()->init();

		m_isReplacing = false;
		m_isAdding = false;
	}
}

std::unique_ptr<Scene>& SceneManager::getActiveScene()
{
	return m_scenes.top();
}
