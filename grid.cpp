#include <iostream>
#include <cstdlib>
#include "grid.h"
#include "ant.h"
#include "doodlebug.h"
#include "organism.h"
using namespace std;

Grid::Grid(unsigned int randomSpot) {
    srand(randomSpot);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gameGrid[i][j] = NULL;
        }
    }
    makeOrg(true, ANTS);
    makeOrg(false, DBUGS);
}

Grid::~Grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gameGrid[i][j] != NULL) {
                delete gameGrid[i][j];
            }
        }
    }
}

Organism* Grid::start(int x, int y) const {
    if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE)) {
        return gameGrid[x][y];
    }else{
        return NULL;
    }
}

void Grid::nextMove(int x, int y, Organism* org) {
    if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE)) {
        gameGrid[x][y] = org;
    }
}

void Grid::userScreen() const {
    int nAnts = 0;
    int nDoodlebugs = 0;

    cout << endl << endl;

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (gameGrid[i][j] == NULL){
                cout << "-";
            }
            else{
                if (gameGrid[i][j]->getType() == true) {
                    nAnts++;
                }
                else if (gameGrid[i][j]->getType() == false) {
                    nDoodlebugs++;
                }
                cout << gameGrid[i][j]->theOrg();
            }
        }
        cout << endl << endl;
    }
    cout << "Number of Ants: " << nAnts << endl;
    cout << "Number of Doodlebugs: " << nDoodlebugs << endl;
}

void Grid::step() {
    resetOrgs();
    moveOrgs(false);//move bugs
    moveOrgs(true);//move ants
    clean();//bugs and ants die
    breedOrgs();//breed
    //userScreen();
}

coords Grid::randomCoords() const{
    coords spot;
    spot.x = rand() % SIZE;
    spot.y = rand() % SIZE;
    return spot;
}


int Grid::randomDirection() const {
    return (rand() % 4);
    // 0 = up
    // 1 = down
    // 2 = left
    // 3 = right
}


void Grid::makeOrg(bool orgType, int count) {
    int numOrgs = 0;
    while (numOrgs < count) {
        coords spot = randomCoords();
        if (gameGrid[spot.x][spot.y] == NULL) {
            numOrgs++;
            if (orgType == true) {
                new Ant(this, spot.x, spot.y);   // Create an true and put it into the gameGrid
            }
            else if (orgType == false) {
                new Doodlebug(this, spot.x, spot.y);   // Create a false and put it into the gameGrid
            }
        }
    }
}

void Grid::resetOrgs() {
    for(int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if(gameGrid[i][j] != NULL){
                gameGrid[i][j]->setMove(false);
            }
        }
    }
}

void Grid::moveOrgs(bool theType) {
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(gameGrid[i][j] != NULL){
                if(gameGrid[i][j]->getType() == theType && !(gameGrid[i][j]->checkMove())){
                    gameGrid[i][j]->move();
                }
            }
        }
    }
}

void Grid::clean() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((gameGrid[i][j] != NULL) && gameGrid[i][j]->isDead()) {
                delete gameGrid[i][j];
                gameGrid[i][j] = NULL;
            }
        }
    }
}

void Grid::breedOrgs() {
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(gameGrid[i][j] != NULL){
                gameGrid[i][j]->breed();
            }
        }
    }
}