#include "Obstacle.h"
Obstacle::Obstacle(Vector2D _pos, float _rad): position(_pos),radius(_rad)
{
}

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle() 
{
}

void Obstacle::Draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), position.x,position.y,radius,255,80,23,255);
}