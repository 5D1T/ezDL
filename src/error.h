#ifndef EZDL_ERROR_H
#define EZDL_ERROR_H

#include <iostream>


void EZDL_Error(const char* msg = NULL, const char* note = NULL)
{
	if(msg != NULL)
	{
		std::cout << "EZDL_Error: " << msg << std::endl;
	}
	std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
	if(note != NULL)
	{
		std::cout << "Note: " << note << std::endl;
	}
}



void EZDL_Assert(bool expr, const char* msg = NULL, const char* note = NULL)
{
	if(!expr)
	{
		EZDL_Error(msg, note);
	}
}


#endif
