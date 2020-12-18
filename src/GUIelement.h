#ifndef GUIELEMENT_H_INCLUDED
#define GUIELEMENT_H_INCLUDED

#include <iostream>


class GUIelement
{
protected:
    SDL_Rect params;
    SDL_Surface* texture = NULL;
public:
    void start(int x, int y, int h, int w, const char* path)
    {
        params.x = x;
        params.y = y;
        params.h = h;
        params.w = w;
        texture = SDL_LoadBMP(path);
        std::cout << path << std::endl;
        if(texture == NULL) 
        {
            std::cout << "Texture of a GUI element is null!" << std::endl;
            std::cout << SDL_GetError() << std::endl;
        }
    }


};


#endif
