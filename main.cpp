#include <iostream>
#include <SDL.h>
#include "time.h"
#include "field.h"
#include "cell.h"
#include "shower.h"
#include "vector"
#include "map"


using namespace std;


void showing(Shower *next, SDL_Rect rect, SDL_Renderer *renderer){
    SDL_Texture *texture = next->LoadTexture();
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, texture, nullptr, &rect, next->rotation(), nullptr, flip);
    SDL_RenderPresent(renderer);
}


vector<SDL_Texture*>  rendering(SDL_Renderer *render, vector<SDL_Texture*> textures) {
    vector<string> places = {"../Templates/pass.bmp", "../Templates/1.bmp", "../Templates/2.bmp", "../Templates/3.bmp"};
    for(auto place : places) {
        SDL_Surface *bmp = SDL_LoadBMP(place.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(render, bmp);
        textures.push_back(texture);
    }
    return textures;
}


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Karcassone (Demo)", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 2560, 1600, SDL_WINDOW_SHOWN);
    SDL_SetWindowFullscreen(window, 0);
    if (window == nullptr) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    vector<SDL_Texture*> textures;

    textures = rendering(renderer, textures);
    for(auto i : textures){
        cout << i << endl;
    }

    vector<vector<int>>field_color;
    srand(time(nullptr));

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    Field *field = new Field();
    Shower *next = new Shower(renderer,
                              textures[rand()%3 + 1],
                              0);
    SDL_Rect new_rect{100, 1200, 300, 300};
    showing(next, new_rect, renderer);

    bool quit = false;
    SDL_Event event;
    int x, y, w, h, x_drag, y_drag, vec_x=0, vec_y=0, rotate=0;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                        case SDLK_r:
                            rotate = (rotate + 1) % 4;
                            next->rotating(rotate);
                            showing(next, new_rect, renderer);
                            break;
                        case SDLK_q:
                            rotate = (rotate - 1) % 4;
                            next->rotating(rotate);
                            showing(next, new_rect, renderer);
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        x_drag = event.button.x;
                        y_drag = event.button.y;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        x = event.button.x;
                        y = event.button.y;
                        if (x_drag == x and y_drag == y) {
                            SDL_Rect rect{x - x % 300, y - y % 300, 300, 300};
                            srand(time(nullptr));
                            Cell *cell = new Cell(x - x % field->call(),
                                                  y - y % field->call(),
                                                  renderer,
                                                  next->WT(),
                                                  rotate);
                            rotate = 0;
                            next->rotating(rotate);
                            field->add_cell(*cell);
                            SDL_Texture *texture = cell->LoadTexture();
                            SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
                            SDL_RendererFlip flip = SDL_FLIP_NONE;
                            SDL_RenderCopyEx(renderer, texture, nullptr, &rect, cell->rotation(), nullptr, flip);
                            SDL_RenderPresent(renderer);
                            next->new_texture(textures[rand()%3 + 1]);
                            showing(next, new_rect, renderer);
                        }
//                        else {
//                        }
                    }
                    break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}