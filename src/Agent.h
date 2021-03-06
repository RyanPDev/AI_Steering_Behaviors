#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include <vector>
#include "utils.h"


class Agent
{
public:
	const float agentRadius = 45;
	class SteeringBehavior
	{
	public:
		
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual Vector2D calculateSteeringForce(Agent* agent, float dtime) = 0;
		void applySteeringForce(Agent* agent, float dtime) {
			Vector2D steeringForce = this->calculateSteeringForce(agent, dtime);
			Vector2D acceleration = steeringForce / agent->getMass();
			Vector2D velocity = agent->getVelocity() + acceleration * dtime;
			velocity.Normalize();
			velocity *= agent->getMaxVelocity();
			agent->setVelocity(velocity);
			agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
		};
	};
private:
	SteeringBehavior* steering_behaviour;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;

	float mass;
	float speed;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Texture* sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	std::vector<Agent*> nearbyAgents;
	Agent();
	~Agent();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();
	void setBehavior(SteeringBehavior* behavior);
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void update(float dtime, SDL_Event* event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames = 1);
	void Agent::GetNearbyAgents(std::vector<Agent*>, float);
};
