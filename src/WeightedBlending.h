#pragma once
#include "Agent.h"
#include <vector>
#include <map>

class WeightedBlending :
	public Agent::SteeringBehavior
{
private:
	std::map<Agent::SteeringBehavior*, float> mSteeringBehaviors;

public:
	WeightedBlending(std::map<Agent::SteeringBehavior*, float>);
	~WeightedBlending();

	Vector2D calculateSteeringForce(Agent* agent, float dtime);
};