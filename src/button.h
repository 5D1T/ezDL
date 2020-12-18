/*
** button.h
** A wrapper for GUI-element, allowing simple user interaction
*/


#ifndef EZDL_BUTTON_H
#define EZDL_BUTTON_H

#include <iostream>
#include <thread>


class Button: public GUIelement
{
private:
    int m_mouseX = 0;
    int m_mouseY = 0;
    bool m_click = false;

public:
    void update(const SDL_Event &e, bool &flip, SDL_Surface* &screen)
    {
        SDL_GetMouseState(&m_mouseX, &m_mouseY);
        switch(e.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            m_click = true;
            break;
        case SDL_MOUSEBUTTONUP: 
            if(m_click &&
              (m_mouseX > params.x && m_mouseX < params.x + params.w) &&
              (m_mouseY > params.y && m_mouseY < params.y + params.h))
              flip ^= 1;
            m_click = false;
            break;
        }
        SDL_BlitSurface(texture, &params, screen, &params);
    }
};


#endif
