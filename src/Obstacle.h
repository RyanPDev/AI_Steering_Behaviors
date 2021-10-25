#pragma once
#include "utils.h"
#include <SDL_image.h>
#include "SDL_SimpleApp.h"

class Obstacle
{
private:
	Vector2D position;
	int radius;

public:
	Obstacle(Vector2D, float);
	Obstacle();
	~Obstacle();
	void Draw();

	Vector2D GetPos()const { return position; }
	void SetPos(Vector2D pos) { position = pos; }
	int GetRadius()const { return radius; }
	void SetRadius(float rad) { radius = rad; }
};