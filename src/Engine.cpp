#include "Engine.h"


Engine::Engine(const string &gameTitle) : gameTitle(gameTitle)
{
}

void Engine::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(gameTitle.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 400, 520, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool Engine::run()
{
    bool running = true;
    SDL_Event event;
    Grid *grid = new Grid("resources/grid.png", renderer, 0, 0);
    mat->draw(renderer, &mat->currentMatrix);
    fontClass->drawFont(renderer, timer->time);
    grid->draw(renderer);
    clock_t start;
    start = clock();
    double duration;
    bool drawAgain;

    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                break;
                case SDL_KEYDOWN:
                    drawAgain = true;
                    switch(event.key.keysym.sym) {
                        case SDLK_UP:
                            if(validation->validPosition(mat->x-1, mat->y, &mat->currentValue, &mat->currentMatrix) ||
                               validation->backwards(mat->x-1, mat->y, "up" , &mat->currentValue, &mat->currentMatrix)){
                                mat->x--;
                            }
                        break;
                        case SDLK_DOWN:
                            if(validation->validPosition(mat->x+1, mat->y, &mat->currentValue, &mat->currentMatrix) ||
                               validation->backwards(mat->x+1, mat->y, "down", &mat->currentValue, &mat->currentMatrix)){
                                mat->x++;
                            }
                        break;
                        case SDLK_LEFT:
                            if(validation->validPosition(mat->x, mat->y-1, &mat->currentValue, &mat->currentMatrix) ||
                               validation->backwards(mat->x, mat->y-1, "left", &mat->currentValue, &mat->currentMatrix)){
                                mat->y--;
                            }
                        break;
                        case SDLK_RIGHT:
                            if(validation->validPosition(mat->x, mat->y+1, &mat->currentValue, &mat->currentMatrix) ||
                               validation->backwards(mat->x, mat->y+1, "right", &mat->currentValue, &mat->currentMatrix)){
                                mat->y++;
                            }
                        break;
                        case SDLK_s:
                            validation->solution();
                            mat->currentValue = 82;
                        break;
                        case SDLK_h:
                            if(mat->currentValue != 82){
                                validation->Hint();
                            }
                        break;
                    }
                break;
            }
        }
        if(drawAgain){
            SDL_RenderClear(renderer);
            grid->draw(renderer);
            mat->draw(renderer, &mat->currentMatrix);
            fontClass->drawFont(renderer, timer->time);
            drawAgain = false;
            SDL_RenderPresent(renderer);
        }

        duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
        if(duration == (int)duration && mat->currentValue != 82){
            timer->CurrentTime();
            drawAgain = true;
        }
    }

    return true;
}

Engine::~Engine()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
