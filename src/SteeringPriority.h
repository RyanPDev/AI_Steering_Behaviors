#pragma once
#include "Agent.h"
#include <queue>
#include "utils.h"
class SteeringPriority :
	public Agent::SteeringBehavior
{
private:
	typedef std::pair<int,Agent::SteeringBehavior*> pi;
	const float THRESHHOLD = 0.003f;
	std::priority_queue<pi> pq;
public:
	SteeringPriority();
	~SteeringPriority();

	void Append(Agent::SteeringBehavior*, int);
	
	Vector2D calculateSteeringForce(Agent* agent, float dtime);
};