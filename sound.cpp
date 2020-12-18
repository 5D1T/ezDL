#include "src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// Window
	
	bool quit = false;
	Window window(100, 100, 1280, 720, "Audio Test");
	
	// Sound
	
	const char* path = "dark_forest.wav";
	int length = (2 * 60 + 46) * 1000;
	
	Sound s;
	s.play(path, length);
	
	// Main loop
	
	while(!quit)
	{
		window.update(quit);
		// ...
		// quit = true;
		window.clearScreen();
	}
	
	SDL_Quit();
}