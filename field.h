//
// Created by lekas on 17.05.2023.
//

#include "vector"
#include "map"
#include "SDL.h"
#include "cell.h"

#ifndef PROJECT_K_FIELD_H
#define PROJECT_K_FIELD_H

using namespace std;

class Field {
private:
    int weight, height, phase, delimiter;

    vector<Cell> matrix;
public:
    Field();
    Field(int _phase, int _delimiter);
    Field(int _weight, int _height, int _phase, int _delimiter);
    void rephase(int _phase);
    void add_cell(Cell point);
    vector<Cell> refuse();
    int call();

};


#endif //PROJECT_K_FIELD_H
