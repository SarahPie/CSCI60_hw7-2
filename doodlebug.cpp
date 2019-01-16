#include "doodlebug.h"
#include "organism.h"
using namespace std;

Doodlebug::Doodlebug(Grid* theGrid, int xc, int yc) : Organism(theGrid, xc, yc){
    stepsToDie = 0;
}

void Doodlebug::move(){
    stepsToBreed++;
    stepsToDie++;
    
    if(grid->start(x, y + 1) != NULL){
        if(grid->start(x, y + 1)->getType() == true){
            stepsToDie = 0;
            delete grid->start(x, y + 1);
            moveTo(x, y + 1);
            return;
        }
    }
    
    if(grid->start(x, y - 1) != NULL){
        if(grid->start(x, y - 1)->getType() == true){
            stepsToDie = 0;
            delete grid->start(x, y - 1);
            moveTo(x, y - 1);
            return;
        }
    }
    
    if(grid->start(x - 1, y) != NULL){
        if(grid->start(x - 1, y)->getType() == true){
            stepsToDie = 0;
            delete grid->start(x - 1, y);
            moveTo(x - 1, y);
            return;
        }
    }
    if(grid->start(x + 1, y) != NULL){
        if(grid->start(x + 1, y)->getType() == true){
            stepsToDie = 0;
            delete grid->start(x + 1, y);
            moveTo(x + 1, y);
            return;
        }
    }
    
    int mDoodlebug = grid->randomDirection();
    switch (mDoodlebug){
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

void Doodlebug::offSpring(int newX, int newY){
    new Doodlebug(this->grid, newX, newY);
    stepsToBreed = 0;
}

void Doodlebug::breed(){
    if(stepsToBreed >= DBREED){
        breedHere();
    }
}

bool Doodlebug::isDead() const{
    if(stepsToDie >= BUGDIES){
        return true;
    }else{
        return false;
    }
}

char Doodlebug::theOrg()const{
    return 'X';
}

bool Doodlebug::getType() const{
    return false;
}

bool Doodlebug::onGrid(int checkX, int checkY)
{
    return (checkX >= 0) && (checkX < SIZE) && (checkY >= 0) && (checkY < SIZE);
}