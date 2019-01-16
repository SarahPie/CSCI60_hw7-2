#include <cstdlib>
#include <iostream>
#include "ant.h"
#include "organism.h"
#include "grid.h"
using namespace std;

Ant::Ant(Grid* theGrid, int xc, int yc) : Organism(theGrid, xc, yc){
    
}

void Ant::move(){
    stepsToBreed++;
    int mAnt = grid->randomDirection();
    switch (mAnt){
        case 0:
            if(grid->start(x, y + 1) == NULL && onGrid(x, y + 1)){
                moveTo(x, y + 1);
            }
            break;
        case 1:
            if(grid->start(x, y - 1) == NULL && onGrid(x, y - 1)){
                moveTo(x, y - 1);
            }
            break;
        case 2:
            if(grid->start(x - 1, y) == NULL && onGrid(x - 1, y)){
                moveTo(x - 1, y);
            }
            break;
        case 3:
            if(grid->start(x + 1, y) == NULL && onGrid(x + 1, y)){
                moveTo(x + 1, y);
            }
            break;
        default:
            break;
    }
}

void Ant::breed(){
    if(stepsToBreed >= ABREED){
        breedHere();
    }
}


void Ant::offSpring(int newX, int newY){
    new Ant(this->grid, newX, newY);
    stepsToBreed = 0;
}


char Ant::theOrg() const{
    return 'O';
}

bool Ant::getType() const{
    return true;
}

bool Ant::onGrid(int checkX, int checkY){
    return (checkX >= 0) && (checkX < SIZE) && (checkY >= 0) && (checkY < SIZE);
}