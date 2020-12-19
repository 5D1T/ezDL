#ifndef EZDL_BUTTON_H
#define EZDL_BUTTON_H

#include <iostream>
#include <thread>


class EZDL_Button: public EZDL_Sprite
{
private:
    bool m_click = false;

public:
    void update(SDL_Event &e, bool &state, SDL_Surface* screen)
    {
        switch(e.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            m_click = true;
            break;
        case SDL_MOUSEBUTTONUP:
            state = (m_click &&
                    (e.button.x >= m_params.x && e.button.x <= m_params.x + m_params.w) &&
                    (e.button.y >= m_params.y && e.button.y <= m_params.y + m_params.h));
            m_click = false;
            break;
        }
        SDL_BlitSurface(m_texture, &m_params, screen, &m_params);
    }
};


#endif
