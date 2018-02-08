#include "Matrix.h"

Matrix::Matrix(const string &path){
    ifstream myfile;
    myfile.open (path);
    if(myfile.is_open()){
        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                myfile >> originalMatrix[i][j];
                currentMatrix[i][j] = originalMatrix[i][j];
                solverMatrix[i][j] = originalMatrix[i][j];
                if(currentMatrix[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
    }else{
        cout<<"Unable to open file"<<endl;
    }
    myfile.close();
}

void Matrix::draw(SDL_Renderer* renderer, int (*matrix)[9][9]){
    stringstream ss;
    SDL_Rect mat_box;
    SDL_Surface* sm;
    SDL_Texture* texture;
    SDL_Color color;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if((*matrix)[i][j] != 0){
                color = {0, 0, 255};
                if((*matrix)[i][j] == currentValue-1){
                    color = {0, 255, 0};
                    ss << (*matrix)[i][j];
                }else if(originalMatrix[i][j] != 0){
                    color = {255, 0, 0};
                    ss << originalMatrix[i][j];
                }else{
                    ss << (*matrix)[i][j];
                }
                sm = TTF_RenderText_Solid(font, ss.str().c_str(), color);
                texture = SDL_CreateTextureFromSurface(renderer, sm);
                mat_box.x = j*44+11;
                mat_box.y = i*44+5;
                mat_box.w = sm->w;
                mat_box.h = sm->h;
                SDL_RenderCopy(renderer, texture, NULL, &mat_box);
                SDL_FreeSurface(sm);
                SDL_DestroyTexture(texture);
                ss.str("");
            }
        }
    }
}
