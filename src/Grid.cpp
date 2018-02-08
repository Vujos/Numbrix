#include "Grid.h"

Grid::Grid(const string &imagePath, SDL_Renderer * const renderer, int x, int y)
{
    SDL_Surface *surface = IMG_Load(imagePath.c_str());
    spriteRect.x = x;
    spriteRect.y = y;
    spriteRect.w = surface->w;
    spriteRect.h = surface->h;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void Grid::draw(SDL_Renderer * const renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &spriteRect);
}
