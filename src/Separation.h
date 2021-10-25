#pragma once
#include "Agent.h"


class Separation :
    public Agent::SteeringBehavior
{  
private:
    const float SEPARATION_RANGE = 70;
public:
    Separation();
    ~Separation();
    Vector2D calculateSteeringForce(Agent*, float);
};