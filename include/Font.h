#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL_ttf.h>

#include <sstream>
#include <iostream>

using namespace std;

class Font{
    public:
        Font(int x, int y);
        void drawFont(SDL_Renderer* renderer, string message);
    protected:
    private:
        int init = TTF_Init();
        TTF_Font* font = TTF_OpenFont("resources/babas.ttf", 110);
        SDL_Color color;
        SDL_Rect message_box;
};

#endif // FONT_H
