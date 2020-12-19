#ifndef EZDL_WINDOW_H
#define EZDL_WINDOW_H


class EZDL_Window
{
private:
    SDL_Window* m_wh = NULL;
    SDL_Rect m_screenrect;

public:
    SDL_Surface* screen = NULL;

    EZDL_Window(int x, int y, int w, int h, const char* name)
	{
	    m_screenrect = {x, y, w, h};
	    m_wh = SDL_CreateWindow(name, x, y, w, h, SDL_WINDOW_SHOWN);
	    EZDL_Assert(m_wh != NULL, "Couldn't create the window");
	}


	void update(SDL_Event &e, bool &quit)
	{
	    screen = SDL_GetWindowSurface(m_wh);
	    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

	    while(SDL_PollEvent(&e))
	    {
	        if(e.type == SDL_QUIT)
	        {
	            quit = true;
	        }
	    }
	}


	void clearScreen()
	{
	    SDL_UpdateWindowSurface(m_wh);
	}
};


#endif
