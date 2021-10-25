#pragma once
#include "Agent.h"
#include "utils.h"
#include "Obstacle.h"

class ObstacleAvoidance:
	public Agent::SteeringBehavior
{
private:
	const float rDistance = 300;
	const float rCheckrate = 10; 

public:
	ObstacleAvoidance::ObstacleAvoidance();
	ObstacleAvoidance::~ObstacleAvoidance();

	const static int numObstacles = 3;

	Obstacle obstacles[5];
	Vector2D ObstacleAvoidance::calculateSteeringForce(Agent*, float);
	Vector2D rayCast(Vector2D posI, float distance, Vector2D dir, float checkDistance);

};