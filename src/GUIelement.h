#ifndef EZDL_UIELEMENT_H
#define EZDL_UIELEMENT_H

#include <cstddef>
#include <iostream>


class UIelement
{
protected:
    SDL_Rect m_params;
    SDL_Surface* m_texture = NULL;
public:
    void start(size_t x, size_t y, size_t h, size_t w, const char* path)
    {
        m_params.x = x;
        m_params.y = y;
        m_params.h = h;
        m_params.w = w;
        m_texture = SDL_LoadBMP(path);
        if(m_texture == NULL) 
        {
            std::cout << "Error: Texture of a UI element is NULL" << std::endl;
            std::cout << SDL_GetError() << std::endl;
        }
    }
};


#endif
