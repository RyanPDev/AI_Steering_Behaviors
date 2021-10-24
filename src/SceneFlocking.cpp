#include "SceneFlocking.h"

SceneFlocking::SceneFlocking() :NUM_AGENTS(50), RADIUS(350)
{
	wBlending.Append(new Seek, 0.f);
	wBlending.Append(new Flee, 0.f);
	wBlending.Append(new Separation, 0.4f);
	wBlending.Append(new Alignment, 0.3f);
	wBlending.Append(new Cohesion, 0.3f);

	for (int i = 0; i < NUM_AGENTS; i++)
	{
		Agent* agent = new Agent;
		agent->setBehavior(&wBlending);
		agent->setPosition(Vector2D(1 + std::rand() / ((RAND_MAX + 1u) / 1280), (1 + std::rand() / ((RAND_MAX + 1u) / 768))));
		agent->setTarget(Vector2D(640, 360));
		agent->loadSpriteTexture("../res/soldier.png", 4);
		agents.push_back(agent);
	}
	target = Vector2D(640, 360);
}

SceneFlocking::~SceneFlocking()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneFlocking::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			for (int i = 0; i < (int)agents.size(); i++)
				agents[i]->setTarget(target);
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < (int)agents.size(); i++)
	{
		agents[i]->GetNearbyAgents(agents, RADIUS);
		agents[i]->update(dtime, event);
	}
}

void SceneFlocking::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();
}

const char* SceneFlocking::getTitle()
{
	return "SDL Steering Behaviors :: Flocking Demo";
}