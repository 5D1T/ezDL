#include "src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	
	// Window
	
	bool quit = false;
	EZDL_Window window(100, 100, 1280, 720, "Text Test");
	
	// Text
	
	SDL_Color color = {0, 0, 0};
	int font_size = 350;
	const char* font_path = "vampiress.ttf";
	SDL_Rect parameters = {300, 100, 1280, 100};
	
	EZDL_Text t(color, font_size, font_path, parameters);
	
	// Main loop
	
	while(!quit)
	{
		window.update(quit);
		t.update("Text", window.screen, true);
		// ...
		window.clearScreen();
	}
	
	TTF_Quit();
	SDL_Quit();
}
