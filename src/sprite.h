#ifndef EZDL_SPRITE_H
#define EZDL_SPRITE_H


class EZDL_Sprite
{
protected:
    SDL_Rect m_params;
    SDL_Surface* m_texture = NULL;

public:
    EZDL_Sprite(int x, int y, int w, int h, const char* texture)
    {
	    m_params = {x, y, w, h};
	    m_texture = SDL_LoadBMP(texture);
	    EZDL_Assert(m_texture != NULL, "Texture of a Sprite is NULL", "The .bmp file is either corrupted or doesn't exist");
	}
};


#endif
