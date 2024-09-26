#pragma once
class Scene
{
public:
	virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;

	virtual void pause() {};
	virtual void resume() {};
};

 