#include "SteeringPriority.h"

SteeringPriority::SteeringPriority()
{
}

SteeringPriority::~SteeringPriority()
{
}
void SteeringPriority::Append(Agent::SteeringBehavior* behavior, int priority)
{
	pq.push(std::make_pair(priority, behavior));
	
	
		//push(std::make_pair(priority, behavior));
	//mSteeringBehaviors.insert(std::pair<SteeringBehavior*, float>(behavior, priority));
}

Vector2D SteeringPriority::calculateSteeringForce(Agent* agent, float dtime)
{
	std::priority_queue<pi> _pq = pq;
	
	std::pair<int, Agent::SteeringBehavior*> p; 
	while (!_pq.empty())
	{
		p = _pq.top();
		if (getLenght(p.second->calculateSteeringForce(agent, dtime)) >= THRESHHOLD)
		{
			return p.second->calculateSteeringForce(agent, dtime).Normalize() * agent->getMaxForce();
		}
		_pq.pop();
	}
	return Vector2D{ 0 };
}