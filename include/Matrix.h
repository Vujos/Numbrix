#ifndef MATRIX_H
#define MATRIX_H

#include <SDL2/SDL_ttf.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Matrix
{
    public:
        Matrix(const string &path);
        void draw(SDL_Renderer* renderer, int (*matra)[9][9]);
        int originalMatrix[9][9];
        int currentMatrix[9][9];
        int solverMatrix[9][9];
        int currentValue = 2;
        int x;
        int y;
    private:
        TTF_Font* font = TTF_OpenFont("resources/babas.ttf", 24);
};

#endif // MATRIX_H
