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
	for (Agent* a : agent->nearbyAgents)
		desiredVelocity += agent->getPosition() - a->getPosition();

	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	Vector2D steeringForce = desiredVelocity - agent->getVelocity();
	steeringForce.Normalize();
	return steeringForce * agent->getMaxForce();
}