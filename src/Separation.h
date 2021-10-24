#pragma once
#include "Agent.h"


class Separation :
    public Agent::SteeringBehavior
{
private:
  
public:

    Separation();
    ~Separation();
    Vector2D calculateSteeringForce(Agent*, float);
};