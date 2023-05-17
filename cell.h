//
// Created by lekas on 17.05.2023.
//

#include "SDL.h"

#ifndef PROJECT_K_CELL_H
#define PROJECT_K_CELL_H

using namespace std;

class Cell {
private:
    SDL_Surface *bmp;
    SDL_Texture *texture;
    SDL_Renderer *render;
    int pos_x, pos_y;
public:
    Cell();
    Cell(int _pos_x, int _pos_y, SDL_Renderer *_render, SDL_Texture *_texture);
    Cell(int _pos_x, int _pos_y, SDL_Renderer *_render, string _place);
    tuple<int, int> position();
    SDL_Texture* LoadTexture();
    SDL_Texture* LoadTexture(SDL_Renderer *_render, string _place);

};

#endif //PROJECT_K_CELL_H
