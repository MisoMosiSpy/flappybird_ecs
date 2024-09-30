#pragma once
class Scene
{
public:
	// The virtual distructor is essential for proper working
	// of smart pointers.
	virtual ~Scene() {};

	virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;

	virtual void pause() {};
	virtual void resume() {};
};

 