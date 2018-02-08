#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

using namespace std;

class Grid {
    public:
        Grid(const string &imagePath, SDL_Renderer * const renderer, int x, int y);
        void draw(SDL_Renderer * const renderer);

        int width() {return spriteRect.w;};
        int height() {return spriteRect.h;};
        void width(int w) {spriteRect.w = w;};
        void height(int h) {spriteRect.h = h;};
    protected:
        SDL_Rect spriteRect;
        SDL_Texture *texture;
};

#endif // GRID_H
