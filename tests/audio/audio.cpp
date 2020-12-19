#include "src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// Window
	
	bool quit = false;
	EZDL_Window window(100, 100, 1280, 720, "Audio Test");
	
	// Audio
	
	const char* path = "dark_forest.wav";
	int length = (2 * 60 + 46) * 1000;
	
	EZDL_Audio a;
	a.play(path, length);
	
	// Main loop
	
	while(!quit)
	{
		window.update(quit);
		// ...
		window.clearScreen();	
	}
	
	SDL_Quit();
}
