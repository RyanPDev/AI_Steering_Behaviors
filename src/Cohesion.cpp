#include "Cohesion.h"

Cohesion::Cohesion()
{
}

Cohesion::~Cohesion()
{
}

Vector2D Cohesion::calculateSteeringForce(Agent* agent, float dtime)
{
	Vector2D averagePosition;
	if (agent->nearbyAgents.empty()) return Vector2D{ 0 };
	else
	{
		for (Agent* a : agent->nearbyAgents)
			averagePosition += a->getPosition();

		averagePosition /= agent->nearbyAgents.size();

		averagePosition -= agent->getPosition();

		averagePosition.Normalize();
		averagePosition *= agent->getMaxVelocity();
		Vector2D steeringForce = averagePosition - agent->getVelocity();
		steeringForce.Normalize();

		return steeringForce * agent->getMaxForce();
	}
}