#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include "SDL_SimpleApp.h"
#include "SceneSeek.h"
#include "SceneFlee.h"
#include "SceneSeekFlee.h"
#include "SceneFlocking.h"

using namespace std;

int main(int argc, char** argv)
{
	std::srand(std::time(nullptr));
	bool quit = false;
	SDL_Event event;
	SDL_SimpleApp* app = SDL_SimpleApp::Instance();

	Scene* curr_scene = new SceneFlocking;
	app->setWindowTitle(curr_scene->getTitle());

	while (!quit)
	{
		// run app frame by frame
		event = app->run(curr_scene);

		/* Keyboard events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
			
			case SDL_SCANCODE_Q:
			case SDL_SCANCODE_ESCAPE:
				quit = true;
				break;
			case SDL_SCANCODE_F:
				app->setFullScreen();
				break;
			}
			break;
		case SDL_QUIT:
			quit = true;
			break;
		}
	}
	return 0;
}