#pragma once
#include "Scene.h"
#include <vector>
#include "Agent.h"
#include "WeightedBlending.h"
#include "Seek.h"
#include "Flee.h"
#include "SteeringPriority.h"


class SceneFlocking :
	public Scene
{
private:
	std::vector<Agent*> agents;
	WeightedBlending wBlending;
	Vector2D target;
	int numAgents;
public:
	SceneFlocking();
	~SceneFlocking();

	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
};