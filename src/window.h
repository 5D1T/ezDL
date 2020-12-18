#ifndef EZDL_WINDOW_H
#define EZDL_WINDOW_H

#include <cstddef>


class EZDL_Window
{
private:
    friend class EZDL_UIelement;
    SDL_Event m_event;
    SDL_Rect m_screenrect;
    
public:
    SDL_Window* wh = NULL;
    SDL_Surface* screen = NULL;

    EZDL_Window(size_t x, size_t y, size_t w, size_t h, const char* name)
    {
        m_screenrect.x = x;
        m_screenrect.y = y;
        m_screenrect.w = w;
        m_screenrect.h = h;
        wh = SDL_CreateWindow(name, m_screenrect.x, m_screenrect.y, m_screenrect.w, m_screenrect.h, SDL_WINDOW_SHOWN);
        if(wh == NULL)
        {
            std::cout << "Error: Couldn't create the window" << std::endl;
        }
    }

    void update(bool &quitflag)
    {
        screen = SDL_GetWindowSurface(wh);
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

        while(SDL_PollEvent(&m_event) != 0)
        {
            quitflag = m_event.type == SDL_QUIT;
        }
    }

    void clearScreen()
    {
        SDL_UpdateWindowSurface(wh);
    }
};


#endif
