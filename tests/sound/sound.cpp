#include "src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// Window
	
	bool quit = false;
	EZDL_Window window(100, 100, 1280, 720, "Audio Test");
	
	// Sound
	
	const char* path = "dark_forest.wav";
	int length = (2 * 60 + 46) * 1000;
	
	EZDL_Sound s;
	s.play(path, length);
	
	// Main loop
	
	SDL_Event e;
	while(!quit)
	{
		window.update(quit);
		// ...
		window.clearScreen();
		// ...
		while(SDL_PollEvent(&e) != 0)
        		if(e.type == SDL_QUIT)
            			quit = true;		
	}
	
	SDL_Quit();
}
