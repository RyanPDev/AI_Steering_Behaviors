#include "Alignment.h"

Alignment::Alignment()
{
}

Alignment::~Alignment()
{
}

Vector2D Alignment::calculateSteeringForce(Agent* agent, float)
{
	Vector2D averageVelocity;
	if (agent->nearbyAgents.empty())
		return agent->getVelocity();
	else
	{
		for (Agent* a : agent->nearbyAgents)
			averageVelocity += a->getVelocity();

		averageVelocity /= agent->nearbyAgents.size();

		averageVelocity.Normalize();
		averageVelocity *= agent->getMaxVelocity();
		Vector2D steeringForce = averageVelocity - agent->getVelocity();
		steeringForce.Normalize();

		return steeringForce * agent->getMaxForce();
	}
}
