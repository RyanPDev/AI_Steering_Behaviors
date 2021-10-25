#pragma once
#include "Scene.h"
#include <vector>
#include "Agent.h"
#include "WeightedBlending.h"
#include "Seek.h"
#include "Flee.h"
#include "SteeringPriority.h"
#include "Separation.h"
#include "Alignment.h"
#include "Cohesion.h"

class SceneFlocking :
	public Scene
{
private:
	std::vector<Agent*> agents;
	WeightedBlending wBlending;
	SteeringPriority pBlending;
	Vector2D target;
	const int NUM_AGENTS;
	const float RADIUS;
public:
	SceneFlocking();
	~SceneFlocking();

	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
};