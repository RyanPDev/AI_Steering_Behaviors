#include "ObstacleAvoidance.h"
ObstacleAvoidance::ObstacleAvoidance()
{
	//Generate obstacles
		obstacles[0].SetPos(Vector2D(500, 400));
		obstacles[1].SetPos(Vector2D(1200, 700));
		obstacles[2].SetPos(Vector2D(1000, 350));
		obstacles[0].SetRadius(100);
		obstacles[1].SetRadius(70);
		obstacles[2].SetRadius(90);

}
ObstacleAvoidance::~ObstacleAvoidance()
{

}
Vector2D ObstacleAvoidance::calculateSteeringForce(Agent* agent, float dtime)
{
	// 45 is +- half the size of the sprite
	Vector2D target = rayCast(agent->getPosition(),rDistance,agent->getVelocity(), rCheckrate);
	if (target == Vector2D{ 0 })
	{
		target = rayCast(agent->getPosition() + getPerpendicularVector(agent->getVelocity().Normalize() * agent->agentRadius, true), rDistance, agent->getVelocity(), rCheckrate);
		if (target == Vector2D{ 0 })
		{
			target = rayCast(agent->getPosition() + getPerpendicularVector(agent->getVelocity().Normalize() * agent->agentRadius, false), rDistance, agent->getVelocity(), rCheckrate);
			if (target == Vector2D{ 0 })
			{
				return target;
			}
		}
	}
	Vector2D desiredVelocity = target - agent->getPosition();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	Vector2D steeringForce = desiredVelocity - agent->getVelocity();
	steeringForce.Normalize();
	return steeringForce * agent->getMaxForce();

}
Vector2D ObstacleAvoidance::rayCast(Vector2D posI, float distance, Vector2D dir, float checkDistance)
{
	dir.Normalize();
	//draw_line(TheApp::Instance()->getRenderer(),posI.x,posI.y,posI.x+dir.x*distance,posI.y+dir.y*distance);
	float currentdistance = 0;
	Vector2D currentPos = posI;
	bool collisionFound = false;
	while (currentdistance <= distance && !collisionFound)
	{
		currentdistance += checkDistance;
		currentPos += dir * currentdistance;
		for (int i = 0; i < numObstacles; i++)
		{
			if (pow((currentPos.x - obstacles[i].GetPos().x), 2) + pow((currentPos.y - obstacles[i].GetPos().y), 2) < pow(obstacles[i].GetRadius(), 2))
			{
				collisionFound = true;
				Vector2D avoidVector = (currentPos - obstacles[i].GetPos()).Normalize();
				Vector2D avoidTarget = obstacles[i].GetPos() + (avoidVector * (distance + obstacles[i].GetRadius()));
				return avoidTarget;
			}
		}
	}
	return Vector2D{ 0 };
}


