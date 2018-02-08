#include "Font.h"

Font::Font(int x, int y){
    color = {255, 255, 255};
    message_box.x = x;
    message_box.y = y;
}

void Font::drawFont(SDL_Renderer * const renderer, string message){
        SDL_Surface* sf = TTF_RenderText_Solid(font, message.c_str(), color);
        message_box.w = sf->w;
        message_box.h = sf->h;
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, sf);
        SDL_RenderCopy(renderer, texture, NULL, &message_box);
        SDL_FreeSurface(sf);
        SDL_DestroyTexture(texture);
}
