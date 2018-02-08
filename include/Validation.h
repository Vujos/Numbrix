#ifndef VALIDATION_H
#define VALIDATION_H

#include "Matrix.h"

#include "vector"
#include "stack"

class Validation
{
    public:
        Validation(Matrix *mat);
        bool validPosition(int x, int y, int *currentValue, int (*matrix)[9][9]);
        bool emptyField(int x, int y, int *currentValue, int (*matrix)[9][9]);
        bool backwards(int x, int y, string currentMove, int *currentValue, int (*matrix)[9][9]);
        void solution();
        void Hint();
        void solver();
    private:
        Matrix *mat;
};
#endif // VALIDATION_H
