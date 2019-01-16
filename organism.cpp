#include <iostream>
#include "organism.h"
#include "grid.h"
using namespace std;

Organism::Organism(Grid* theGrid, int xc, int yc) {
    grid = theGrid;
    x = xc;
    y = yc;
    stepsToBreed = 0;
    moved = false;
    grid->nextMove(x, y, this);
}

void Organism::setMove(bool checkMove) {
    moved = checkMove;
}

bool Organism::checkMove() const {
    return moved;
}

void Organism::moveTo(int newX, int newY) {

        grid->nextMove(newX, newY, grid->start(x, y));
        grid->nextMove(x, y, NULL);
        x = newX;
        y = newY;
        grid->start(x, y)->setMove(true);
}


void Organism::breedHere(){
    
    if((grid->start(x, y + 1) == NULL) && onGrid(x, y + 1)){
        offSpring(x, y + 1);
    }

    else if((grid->start(x, y - 1) == NULL) && onGrid(x, y - 1)){
        offSpring(x, y - 1);
    }

    else if((grid->start(x - 1, y) == NULL)  && onGrid(x - 1, y)){
        offSpring(x - 1, y);
    }

    else if((grid->start(x + 1, y) == NULL)  && onGrid(x + 1, y)){
        offSpring(x + 1, y);
    }
}

bool Organism::onGrid(int checkX, int checkY){
    return (checkX >= 0) && (checkX < SIZE) && (checkY >= 0) && (checkY < SIZE);
}

bool Organism::isDead() const {
    return false;
}