#include "WeightedBlending.h"

WeightedBlending::WeightedBlending(std::map<Agent::SteeringBehavior*, float>)
{
}

WeightedBlending::~WeightedBlending()
{
}

Vector2D WeightedBlending::calculateSteeringForce(Agent* agent, float dtime)
{
	Vector2D steeringForce_total = Vector2D{ 0 };

	for (std::map<Agent::SteeringBehavior*, float>::iterator it = mSteeringBehaviors.begin(); it != mSteeringBehaviors.end(); ++it)
	{
		steeringForce_total += it->first->calculateSteeringForce(agent, dtime) * it->second;
	}

	//	Vector2D acceleration = steeringForce_total / agent->getMass();
	//	speed += acceleration * dtime;
	//	if (speed.Length() > agent->getMaxVelocity())
	//	{
	//		speed = speed.Normalize() * agent->getMaxVelocity();
	//	}

	return steeringForce_total * agent->getMaxForce();
}