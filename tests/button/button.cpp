#include <iostream>
#include "src/ezDL.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// Window
	
	bool quit = false;
	EZDL_Window window(100, 100, 1280, 720, "Button Test");
	
	// Button
	
	int width  = 500;
	int height = 500;
	int x = (1280 - width) / 2;
	int y = (720 - height) / 2;
	const char* texture_path = "cheese.bmp";
	
	SDL_Event e;
	bool state = false;
	EZDL_Button b(x, y, width, height, texture_path);
	
	// Main loop
	
	while(!quit)
	{
		window.update(e, quit);
		b.update(window.screen, e, state);
		// ...
		window.clearScreen();
		// ...
		if(state)
		{
			std::cout << "clicked" << std::endl;
		}
	}
	
	SDL_Quit();
}
