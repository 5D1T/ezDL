#include "src/ezDL.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// Window
	
	bool quit = false;
	EZDL_Window window(100, 100, 1280, 720, "Audio Test");
	
	// Sound
	
	const char* path = "dark_forest.wav";
	int length = (2 * 60 + 46) * 1000;
	
	EZDL_Audio a(path, length);
	a.play();
	
	// Main loop
	
	SDL_Event e;
	while(!quit)
	{
		window.update(e, quit);
		// ...
		window.clearScreen();	
	}
	
	SDL_Quit();
	return 0;
}
