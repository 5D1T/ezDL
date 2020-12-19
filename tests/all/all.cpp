#include "src/ezDL.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	// Window

	bool quit = false;
	EZDL_Window w(100, 100, 1280, 720, "EZDL Test");

	// Text

	EZDL_Text t(200, "vampiress.ttf", {0,0,0}, {20, 20, 1280, 100});

	// Audio

	EZDL_Audio a("dark_forest.wav", (2 * 60 + 46) * 1000);
	a.play();

	// Button

	SDL_Event e;
	bool state = false;
	EZDL_Button b(390, 110, 500, 500, "cheese.bmp");

	// Main loop

	while(!quit)
	{
		w.update(e, quit);
		t.update(w.screen, "EZDL", true);
		b.update(w.screen, e, state);
		w.clearScreen();

		if(state)
		{
			std::cout << "clicked" << std::endl;
		}
	}

	TTF_Quit();
	SDL_Quit();
}
