#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include <iostream>
using namespace std;



#endif // TEXT_H_INCLUDED

class Text
{
private:
SDL_Color colour = {255,255,255};
SDL_Surface* textSurface = NULL;
SDL_Rect params;
TTF_Font* ttffont = NULL;
bool visible;

public:

    Text(SDL_Color a,int fontsize, const char* font,SDL_Rect parameters)
    {
        cout<<font<<endl;
        colour = a;
        ttffont = TTF_OpenFont(font, fontsize);
        params = parameters;

        if(TTF_OpenFont(font, fontsize) == NULL) //NULL CHECK (kinda like a vibe check)
        {
            cout<<SDL_GetError()<<endl;  //problem with loading font file
        }

        if(TTF_RenderText_Solid(ttffont,"default",colour) == NULL)
        {
            cout<<SDL_GetError()<<endl;
        }
       params = parameters;
    }

    void Update(const char* text,SDL_Surface* &screen, bool visible)
    {
        if(visible)
        {
            textSurface = TTF_RenderText_Solid(ttffont,text,colour);
            SDL_BlitSurface(textSurface,NULL,screen,&params);
        }
    }

    void Yeet()
    {
        TTF_CloseFont(ttffont);
        SDL_FreeSurface(textSurface);
    }

};
