#include "Validation.h"

Validation::Validation(Matrix *matrix){
    mat = matrix;
    solver();
}

void Validation::solution(){
    for (int i = 0; i<9; i++) {
        for (int j = 0; j<9; j++) {
            mat->currentMatrix[i][j] = mat->solverMatrix[i][j];
        }
    }
}

bool Validation::validPosition(int x, int y, int *currentValue, int (*matrix)[9][9]){
    if(x >= 0 && x <= 8 && y >= 0 && y <= 8){
        if(emptyField(x,y, currentValue, &(*matrix))){
            return true;
        }
    }
    return false;
}

bool Validation::emptyField(int x, int y, int *currentValue, int (*matrix)[9][9]){
    if((*matrix)[x][y] == 0 || (*matrix)[x][y] == *currentValue){
        (*matrix)[x][y] = *currentValue;
        *currentValue+=1;
        return true;
    }
    return false;
}

bool Validation::backwards(int x, int y, string currentMove, int *currentValue, int (*matrix)[9][9]){
    if((*matrix)[x][y] != *currentValue-2){
        return false;
    }
    int counter = 0;
    int oldX = x;
    int oldY = y;

    if(currentMove == "up")
        x++;
    if(currentMove == "down")
        x--;
    if(currentMove == "right")
        y--;
    if(currentMove == "left")
        y++;

    if((*matrix)[x-1][y] == *currentValue-2)
        counter++;
    if((*matrix)[x+1][y] == *currentValue-2)
        counter++;
    if((*matrix)[x][y-1] == *currentValue-2)
        counter++;
    if((*matrix)[x][y+1] == *currentValue-2)
        counter++;

    if(counter > 1){
        if(mat->originalMatrix[oldX][oldY] == *currentValue-2){
            return false;
        }
        counter--;
    }
    if(counter == 1){
        *currentValue -= 1;
        if(mat->originalMatrix[x][y] == 0){
            (*matrix)[x][y] = 0;
        }
        return true;
    }
    return false;
}

void Validation::Hint(){
    bool rightWay = true;
    int xV, xM, yV, yM;
    bool wrongWay = false;
    for (int i = 0; i<9; i++) {
        for (int j = 0; j<9; j++) {
            if(mat->currentMatrix[i][j] == mat->currentValue-2){
                if(mat->currentValue-2 != mat->originalMatrix[i][j] || rightWay){
                    xM = i;
                    yM = j;
                    rightWay = false;
                }
            }
            if(mat->solverMatrix[i][j] == mat->currentValue){
                xV = i;
                yV = j;
            }
            if(mat->currentMatrix[i][j] != 0 && mat->currentMatrix[i][j] != mat->solverMatrix[i][j]){
                wrongWay = true;
            }
        }
    }
    if(wrongWay){
        mat->currentMatrix[mat->x][mat->y] = 0;
        mat->x = xM;
        mat->y = yM;
        mat->currentValue--;
    }else{
        mat->currentMatrix[xV][yV] = mat->currentValue;
        mat->x = xV;
        mat->y = yV;
        mat->currentValue++;
    }
}

void Validation::solver(){
    stack <int> stek;
    int lastMove = 0;
    int currentValue = mat->currentValue;
    int x = mat->x;
    int y = mat->y;
    while(currentValue != 82){
        if(lastMove <= 0 && validPosition(x-1, y, &currentValue, &mat->solverMatrix)){
            lastMove = 1;
            x--;
        }
        else if(lastMove <= 1 && validPosition(x+1, y, &currentValue, &mat->solverMatrix)){
            lastMove = 2;
            x++;
        }
        else if(lastMove <= 2 && validPosition(x, y-1, &currentValue, &mat->solverMatrix)){
            lastMove = 3;
            y--;
        }
        else if(lastMove <= 3 && validPosition(x, y+1, &currentValue, &mat->solverMatrix)){
            lastMove = 4;
            y++;
        }
        else{
            lastMove = 5;
        }
        if(lastMove == 5){
            if(backwards(x-1, y, "up", &currentValue, &mat->solverMatrix)){
                x--;
            }
            else if(backwards(x+1, y, "down", &currentValue, &mat->solverMatrix)){
                x++;
            }
            else if(backwards(x, y-1, "left", &currentValue, &mat->solverMatrix)){
                y--;
            }
            else if(backwards(x, y+1, "right", &currentValue, &mat->solverMatrix)){
                y++;
            }
            lastMove = stek.top();
            stek.pop();
        }else{
            stek.push(lastMove);
            lastMove = 0;
        }
    }
}
