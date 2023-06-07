//
// Created by lekas on 17.05.2023.
//

#include "field.h"
#include "cell.h"
#include "shower.h"
#include "SDL.h"
#include "iostream"


Field::Field() {
    weight = 2560; height = 1440; phase = 0; delimiter = 300;
}

Field::Field(int _phase, int _delimiter) {
    weight = 2560; height = 1440; phase = _phase; delimiter = _delimiter;
}

Field::Field(int _weight, int _height,int _phase, int _delimiter) {
    weight = _weight; height = _height; phase = _phase; delimiter = _delimiter;
}

void Field::rephase(int _phase) {
    phase=_phase;
}

void Field::add_cell(Cell point) {
    matrix.push_back(point);
}

vector<Cell> Field::refuse() {
    return matrix;
}

int Field::call() {
    return delimiter;
}


Cell::Cell() {
    string place = "tamplates/pass.bmp";
    bmp = nullptr;
    texture = nullptr;
    bmp = SDL_LoadBMP(place.c_str());
}

Cell::Cell(int _pos_x, int _pos_y, SDL_Renderer *_render, SDL_Texture *_texture, int _rotate) {
    pos_x = _pos_x; pos_y = _pos_y; rotate = _rotate;
    bmp = nullptr;
    texture = _texture;
    render = _render;
}

Cell::Cell(int _pos_x, int _pos_y, SDL_Renderer *_render, string _place) {
    pos_x = _pos_x; pos_y = _pos_y;
    bmp = nullptr;
    texture = nullptr;
    render = _render;
    cout << _place << endl;
    bmp = SDL_LoadBMP(_place.c_str());
    cout << bmp << endl;
    if (bmp != nullptr){
        texture = SDL_CreateTextureFromSurface(render, bmp);
//        SDL_FreeSurface(bmp);
    }
}

tuple<int, int> Cell::position() {
    return make_tuple(pos_x, pos_y);
}

SDL_Texture * Cell::LoadTexture() {
    if (bmp != nullptr){
        texture = SDL_CreateTextureFromSurface(render, bmp);
        SDL_FreeSurface(bmp);
    }
    else
        cout << 0 << endl;
        cout << SDL_GetError() << endl;
    return texture;
}

SDL_Texture* Cell::ReturnTexture() {
    return texture;
}

SDL_Texture * Cell::LoadTexture(SDL_Renderer *_render, string _place) {
    bmp = nullptr;
    texture = nullptr;
    cout << _place << endl;
    bmp = SDL_LoadBMP(_place.c_str());
    cout << bmp << endl;
    if (bmp != nullptr){
        texture = SDL_CreateTextureFromSurface(render, bmp);
        SDL_FreeSurface(bmp);
    }
    else
        cout << SDL_GetError() << endl;
    return texture;
}

int Cell::rotation() {
    return rotate*90;
}

void Shower::rotating(int degree) {
    rotate = degree;
}

Shower::Shower(SDL_Renderer *_render, SDL_Texture *_texture, int _rotate) {
    rotate = _rotate;
    bmp = nullptr;
    texture = _texture;
    render = _render;
}

SDL_Texture * Shower::LoadTexture() {
    if (bmp != nullptr){
        texture = SDL_CreateTextureFromSurface(render, bmp);
        SDL_FreeSurface(bmp);
    }
    else
        cout << 0 << endl;
    cout << SDL_GetError() << endl;
    return texture;
}