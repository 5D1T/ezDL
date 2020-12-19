#ifndef EZDL_TEXT_H
#define EZDL_TEXT_H

#include <cstddef>


class EZDL_Text
{
private:
    SDL_Rect m_params;
    TTF_Font* m_ttffont = NULL;
    SDL_Surface* m_textSurface = NULL;
    SDL_Color m_color = {255, 255, 255};

public:
	EZDL_Text(size_t font_size, const char* font, SDL_Color color, SDL_Rect params)
	{
	    m_color = color;
	    m_ttffont = TTF_OpenFont(font, font_size);

	    EZDL_Assert(TTF_OpenFont(font, font_size)                     != NULL, "Couldn't load the font file");
	    EZDL_Assert(TTF_RenderText_Solid(m_ttffont, "default", color) != NULL, "Couldn't render the text");
	    
	    m_params = params;
	}

	~EZDL_Text()
	{
		TTF_CloseFont(m_ttffont);
	    SDL_FreeSurface(m_textSurface);
	}

	void update(SDL_Surface* screen, const char* text, bool visible)
	{
	    if(visible)
	    {
	        m_textSurface = TTF_RenderText_Solid(m_ttffont, text, m_color);
	        SDL_BlitSurface(m_textSurface, NULL, screen, &m_params);
	    }
	}
};


#endif
