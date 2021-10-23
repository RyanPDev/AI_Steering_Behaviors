#pragma once
#include "Agent.h"
#include <queue>

class SteeringPriority :
	public Agent::SteeringBehavior
{
private:
	std::priority_queue<Agent::SteeringBehavior*> priorityBehaviors;

public:
	SteeringPriority();
	~SteeringPriority();

	
	
	Vector2D calculateSteeringForce(Agent* agent, float dtime);
};