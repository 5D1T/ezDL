#ifndef EZDL_TEXT_H
#define EZDL_TEXT_H

#include <iostream>


class Text
{
private:
    SDL_Color m_color = {255,255,255};
    SDL_Surface* m_textSurface = NULL;
    SDL_Rect m_parameters;
    TTF_Font* m_ttffont = NULL;

public:
    Text(SDL_Color color, int fontsize, const char* font, SDL_Rect parameters)
    {
        // std::cout << ">> using font: " << font << std::endl;
        m_color = color;
        m_ttffont = TTF_OpenFont(font, fontsize);

        if(TTF_OpenFont(font, fontsize) == NULL)
        {
            // Error: Couldn't load the font file
            std::cout << SDL_GetError() << std::endl;
        }

        if(TTF_RenderText_Solid(m_ttffont, "default", color) == NULL)
        {
            // Error: Couldn't render the text
            std::cout << SDL_GetError() << std::endl;
        }
        
       m_parameters = parameters;
    }

    void Update(const char* text, SDL_Surface* &screen, bool visible)
    {
        if(visible)
        {
            m_textSurface = TTF_RenderText_Solid(m_ttffont, text, m_color);
            SDL_BlitSurface(m_textSurface, NULL, screen, &m_parameters);
        }
    }

    void Free()
    {
        TTF_CloseFont(m_ttffont);
        SDL_FreeSurface(m_textSurface);
    }
};


#endif
