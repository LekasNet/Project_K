//
// Created by lekas on 27.05.2023.
//

#include "SDL.h"
#include "cell.h"

#ifndef PROJECT_K_SHOWER_H
#define PROJECT_K_SHOWER_H


class Shower: public Cell {
private:
    SDL_Surface *bmp;
    SDL_Texture *texture;
    SDL_Renderer *render;
    int pos_x = 100, pos_y = 1200, rotate=0;
    bool unique = false;
public:
    Shower();
    Shower(SDL_Renderer *_render, SDL_Texture *_texture, int _rotate);
    void rotating(int degree);
    void new_texture(SDL_Texture *_texture) {texture = _texture;};
    SDL_Texture* LoadTexture();
    SDL_Texture* WT(){return texture;};
    int rotation(){return rotate*90;}
};


#endif //PROJECT_K_SHOWER_H
