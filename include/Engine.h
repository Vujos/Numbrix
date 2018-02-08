#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <sstream>
#include <iostream>
#include <ctime>

#include "Grid.h"
#include "Validation.h"
#include "Font.h"
#include "Timer.h"

using namespace std;

class Engine {
    public:
        Engine(const string &gameTitle);
        virtual ~Engine();
        Timer *timer = new Timer();
        Font *fontClass = new Font(0, 375);
        Matrix *mat = new Matrix("resources/numbrix.txt");
        Validation *validation = new Validation(mat);
        void init();
        bool run();
    private:
        string gameTitle;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif // ENGINE_H
