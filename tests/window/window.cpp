#include "../../src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	int x = 100;
	int y = 100;
	int width  = 1280;
	int height = 720;
	const char* name = "Window Test";

	bool quit = false;
	Window window(x, y, width, height, name);

	while(!quit)
	{
		window.update(quit);
		// ...
		window.clearScreen();
		// ...
		// quit = true;
	}

	SDL_Quit();
}
