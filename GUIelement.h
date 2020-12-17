#ifndef GUIELEMENT_H_INCLUDED
#define GUIELEMENT_H_INCLUDED
#include<iostream>
using namespace std;

#endif // GUIELEMENT_H_INCLUDED

class GUIelement
{
protected:
    SDL_Rect params;
    SDL_Surface* texture = NULL;
public:
    void start(int x,int y,int h, int w, const char* path)
    {
        params.x = x;
        params.y = y;
        params.h = h;
        params.w = w;
        texture = SDL_LoadBMP(path);
        cout<<path<<endl;
        if(texture == NULL)  //yo fuck try catch, all my homies use if statements
        {
            cout<<"Texture of a GUI element is null!"<<endl;
            cout<<SDL_GetError()<<endl;
        }
    }


};
