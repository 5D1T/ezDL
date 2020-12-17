#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED
using namespace std;

#endif // WINDOW_H_INCLUDED

class Window
{


private:
    bool quit = false;
    friend class GUIelement;
    SDL_Event e;
    SDL_Rect screenrect;
public:
    SDL_Window* s1 = NULL;
     SDL_Surface* screen = NULL;



    Window(int x,int y, int w, int h, const char* name)
    {
        screenrect.x = x;
        screenrect.y = y;
        screenrect.w = w;
        screenrect.h = h;
        s1 = SDL_CreateWindow( name, screenrect.x, screenrect.y, screenrect.w, screenrect.h, SDL_WINDOW_SHOWN );
        if (s1 == NULL)
        {
            cout<<"creating window failed"<<endl;
        }
    }

    void Update(bool &quitflag)
    {
        screen = SDL_GetWindowSurface(s1);
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));

        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quitflag = true;
            }
        }
    }

    void ClearScreen()
    {
        SDL_UpdateWindowSurface(s1);
    }
};
