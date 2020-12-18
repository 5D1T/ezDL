#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED


class Window
{
private:
    friend class GUIelement;
    SDL_Event m_event;
    SDL_Rect m_screenrect;
    
public:
    SDL_Window* wh = NULL;
    SDL_Surface* screen = NULL;

    Window(int x,int y, int w, int h, const char* name)
    {
        m_screenrect.x = x;
        m_screenrect.y = y;
        m_screenrect.w = w;
        m_screenrect.h = h;
        wh = SDL_CreateWindow(name, screenrect.x, screenrect.y, screenrect.w, screenrect.h, SDL_WINDOW_SHOWN);
        if(wh == NULL)
        {
            // Errror: Couldn't create the window
            std::cout << "Error: Couldn't create the window" << std::endl;
        }
    }

    void Update(bool &quitflag)
    {
        screen = SDL_GetWindowSurface(wh);
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255,255,255));

        while(SDL_PollEvent(&m_event) != 0)
        {
            /*
            if(m_event.type == SDL_QUIT)
            {
                quitflag = true;
            }
            */
            quitflag = m_event.type == SDL_QUIT;
        }
    }

    void ClearScreen()
    {
        SDL_UpdateWindowSurface(wh);
    }
};


#endif
