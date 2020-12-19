#include "src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	// Window

	bool quit = false;
	EZDL_Window w(100, 100, 1280, 720, "EZDL Test");

	// Text

	EZDL_Text t({0,0,0}, 250, "vampiress.ttf", {20, 20, 1280, 100});

	// Audio

	EZDL_Audio a;
	a.play("dark_forest.wav", (2 * 60 + 46) * 1000);

	// Button

	SDL_Event e;
	EZDL_Button b;
	bool state = false;
	b.init(390, 110, 500, 500, "cheese.bmp");

	// Main loop

	while(!quit)
	{
		w.update(e, quit);
		t.update("EZDL", w.screen, true);
		b.update(e, state, w.screen);
		w.clearScreen();

		if(state)
		{
			std::cout << "clicked" << std::endl;
		}
	}

	TTF_Quit();
	SDL_Quit();
}
