#ifndef EZDL_TEXT_H
#define EZDL_TEXT_H

#include <cstddef>
#include <iostream>


class EZDL_Text
{
private:
    SDL_Color m_color = {255,255,255};
    SDL_Surface* m_textSurface = NULL;
    SDL_Rect m_params;
    TTF_Font* m_ttffont = NULL;

public:
    Text(SDL_Color color, size_t fontsize, const char* font, SDL_Rect params)
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
        
       m_params = params;
    }

    void update(const char* text, SDL_Surface* screen, bool visible)
    {
        if(visible)
        {
            m_textSurface = TTF_RenderText_Solid(m_ttffont, text, m_color);
            SDL_BlitSurface(m_textSurface, NULL, screen, &m_params);
        }
    }

    void free()
    {
        TTF_CloseFont(m_ttffont);
        SDL_FreeSurface(m_textSurface);
    }
};


#endif
