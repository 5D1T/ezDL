#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <iostream>
#include<thread>

using namespace std;

#endif // BUTTON_H_INCLUDED

class Button: public GUIelement
{
private:
    bool quitflag = false;
    int mouseX = 0;
    int mouseY = 0;
    bool click = false;

public:
    void Update(SDL_Event &e,bool &flip, SDL_Surface* &screen)  //passing by reference kinda thicc
    {
        SDL_GetMouseState(&mouseX,&mouseY);
        switch(e.type)
        {
        case SDL_MOUSEBUTTONDOWN:

            click = true;
            break;

        case SDL_MOUSEBUTTONUP:
            if (click)
            {
                if(mouseX > params.x && mouseX < params.x + params.w)
                {
                    if(mouseY > params.y && mouseY < params.y + params.h)
                    {
                        if(flip == true)
                        {
                            flip = false;
                        }
                        else
                        {
                            flip = true;
                        }
                    }
                }
            }
            click = false;
            break;
        }
    SDL_BlitSurface(texture,&params,screen,&params);
    }
};
