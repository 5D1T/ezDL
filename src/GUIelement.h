/*
** GUIelement.h
** Allows low-level GUI-element manipulation
*/


#ifndef EZDL_GUIELEMENT_H
#define EZDL_GUIELEMENT_H

#include <iostream>


class GUIelement
{
protected:
    SDL_Rect m_params;
    SDL_Surface* m_texture = NULL;
public:
    void start(int x, int y, int h, int w, const char* path)
    {
        m_params.x = x;
        m_params.y = y;
        m_params.h = h;
        m_params.w = w;
        m_texture = SDL_LoadBMP(path);
        std::cout << path << std::endl;
        if(texture == NULL) 
        {
            std::cout << "Error: Texture of a GUI element is NULL" << std::endl;
            std::cout << SDL_GetError() << std::endl;
        }
    }
};


#endif
