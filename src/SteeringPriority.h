#pragma once
#include "Agent.h"

class SteeringPriority :
	public Agent::SteeringBehavior
{
private:


public:
	SteeringPriority();
	~SteeringPriority();

	Vector2D calculateSteeringForce(Agent* agent, float dtime);


};