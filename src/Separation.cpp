#include "Separation.h"

Separation::Separation()
{

}

Separation::~Separation()
{

}

Vector2D Separation::calculateSteeringForce(Agent* agent, float dtime)
{
	Vector2D desiredVelocity;
	if (agent->nearbyAgents.empty()) return Vector2D{ 0 };
	else
	{
		for (Agent* a : agent->nearbyAgents)
		{
			
			if(getDistance(agent->getPosition(),a->getPosition()) < SEPARATION_RANGE + agent->agentRadius*2)
				desiredVelocity += agent->getPosition() - a->getPosition();

		}
		desiredVelocity /= agent->nearbyAgents.size();

		desiredVelocity.Normalize();
		desiredVelocity *= agent->getMaxVelocity();
		Vector2D steeringForce = desiredVelocity - agent->getVelocity();
		steeringForce.Normalize();

		return steeringForce * agent->getMaxForce();
	}
}