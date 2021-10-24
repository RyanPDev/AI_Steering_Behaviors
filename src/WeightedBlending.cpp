#include "WeightedBlending.h"

WeightedBlending::WeightedBlending()
{
	
}

WeightedBlending::~WeightedBlending()
{
}
void WeightedBlending::Append(Agent::SteeringBehavior* behavior, float weight)
{
	mSteeringBehaviors.insert(std::pair<SteeringBehavior*, float>(behavior, weight));
}

Vector2D WeightedBlending::calculateSteeringForce(Agent* agent, float dtime)
{
	Vector2D steeringForce_total = Vector2D{ 0 };

	for (std::map<Agent::SteeringBehavior*, float>::iterator it = mSteeringBehaviors.begin(); it != mSteeringBehaviors.end(); ++it)
	{
		steeringForce_total += it->first->calculateSteeringForce(agent, dtime) * it->second;
	}

	return steeringForce_total * agent->getMaxForce();
}