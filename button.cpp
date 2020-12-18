#include "src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// Window
	
	bool quit = false;
	Window window(100, 100, 1280, 720, "Button Test");
	
	// Button
	
	int width  = 500;
	int height = 500;
	int x = (1280 - width) / 2;
	int y = (720 - height) / 2;
	const char* texture_path = "cheese.bmp";
	
	SDL_Event e;
	bool flip = false;
	Button b;
	b.start(x, y, width, height, texture_path);
	
	// Main loop
	
	while(!quit)
	{
		window.update(quit);
		b.update(e, flip, window.screen);
		// ...
		// quit = true;
		window.clearScreen();
	}
	
	SDL_Quit();
}