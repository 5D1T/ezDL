#include "src/ezDL.h"


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
	
	EZDL_Text t(font_size, font_path, color, parameters);
	
	// Main loop
	
	SDL_Event e;
	while(!quit)
	{
		window.update(e, quit);
		t.update(window.screen, "Text", true);
		// ...
		window.clearScreen();
	}
	
	t.free();
	TTF_Quit();
	SDL_Quit();
}
